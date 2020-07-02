/*
 * Example illustrating a HTTP client.
 *
 * Usage:
 *    ./distribution/example/http_client
 */

#include <memory>
#include <future>
#include <cstdio>
#include <cstdlib>
#include <restbed>

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/time.h>

void print(const std::shared_ptr<restbed::Response>& response)
{
    fprintf(stderr, "*** Response ***\n");
    fprintf(stderr, "Status Code:    %i\n", response->get_status_code());
    fprintf(stderr, "Status Message: %s\n", response->get_status_message().data());
    fprintf(stderr, "HTTP Version:   %.1f\n", response->get_version());
    fprintf(stderr, "HTTP Protocol:  %s\n", response->get_protocol().data());

    for (const auto header : response->get_headers())
    {
        fprintf(stderr, "Header '%s' > '%s'\n", header.first.data(), header.second.data());
    }

    auto length = response->get_header("Content-Length", 0);

    restbed::Http::fetch(length, response);

    fprintf(stderr, "Body:           %.*s...\n\n", 25, response->get_body().data());
}

int main(const int, const char**)
{
    auto request = std::make_shared<restbed::Request>(
                restbed::Uri("http://127.0.0.1:1984/resource/libeio"));
    request->set_header("Connection", "keep-alive");

    std::thread th1([](){});


    time_t btime = time(nullptr);
    int i, counter = 0;
    for (i = 0; i < 2000; i++) {
        request->set_header("MyName", "Libeio");
        request->set_header("index", std::to_string(i));
        auto response = restbed::Http::sync(request);
        // print( response );
        if (response->get_status_code() == 200) {
            counter++;
        }
    }
    
    time_t etime = time(nullptr);
    
    std::cout << "counter=" << counter << ", consumed " << etime - btime << " seconds"<< std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
