#include <iostream>
#include <emscripten/emscripten.h>
#include <unistd.h>
//emcc -std=c++11 worker.cpp -s EXPORTED_FUNCTIONS="['_one']" -o worker.js  -s BUILD_AS_WORKER=1
extern "C" {

void one(char* data, int size) {
    for(int i=0; i<10; i++) {
        //std::cout << "Worker" << std::endl;
        //emscripten_worker_respond_provisionally(data, size);
    }
    
    sleep (10);
    emscripten_worker_respond(data, size);
}
}