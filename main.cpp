#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <emscripten.h>
#include <pthread.h>
#include <SDL.h>
#include <future>

#include <emscripten/bind.h>

#include <thread>
#include <iostream>

#include <emscripten/threading.h>

//emcc main.cpp -o main.js -s EXPORTED_FUNCTIONS="['_async']" -s RESERVED_FUNCTION_POINTERS=2 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=2 -s ASYNCIFY=1 -s ASYNCIFY_FUNCTIONS="['_async']" -std=c++11 --bind

extern "C" {

void (*g_callBack)(const char*);

	
void onMessage(char *data, int size, void *arg) 
{
  assert((int)arg == 93);
  int *x = (int*)data;
  
  emscripten_run_script("window.parent.postMessage('Hello from postMessage', '*');");
  g_callBack ("Hello from callBack!");//Call callback from index.html
  EM_ASM( finished() );//Call function finished from index.html
  
}

void async(void (*callBack)(const char*))
{
	int x[2] = { 100, 6002 };
	
	g_callBack = callBack;
	
	worker_handle  work = emscripten_create_worker("worker.js");
  emscripten_call_worker(work, "one", (char*)x, sizeof(x), onMessage, (void*)93);	

}

}