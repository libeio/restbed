/**
 * 测试方法:
 *  curl -w'\n' -v -X GET http://localhost:1984/resource/libei
 */

#include <string>
#include <memory>
#include <iostream>
#include <restbed>

void get_method_handler(const std::shared_ptr<restbed::Session> session)
{
    const auto& request = session->get_request();
    
    std::cout << "my name=" << request->get_header("MyName") << std::endl;
    std::cout << "index=" << request->get_header("index", 0) << std::endl;
    
    const std::string body = "Hello, " + request->get_path_parameter("name");
        
    session->yield(restbed::OK, body, { { "Content-Length", std::to_string(body.size()) },
                                        { "Connection", "keep-alive" } } );
}

int main( const int, const char** )
{
    auto resource = std::make_shared<restbed::Resource>();
    resource->set_path("/resource/{name: .*}");
    resource->set_method_handler("GET", get_method_handler);
    
    auto settings = std::make_shared<restbed::Settings>();
    settings->set_port(1984);
    
    restbed::Service service;
    service.publish(resource);
    service.start(settings);
    
    return 0;
}
