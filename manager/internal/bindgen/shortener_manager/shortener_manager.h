// Generated by `wit-bindgen` 0.11.0. DO NOT EDIT!
#ifndef __BINDINGS_SHORTENER_MANAGER_H
#define __BINDINGS_SHORTENER_MANAGER_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
  char*ptr;
  size_t len;
} shortener_manager_string_t;

typedef struct {
  shortener_manager_string_t f0;
  shortener_manager_string_t f1;
} shortener_manager_tuple2_string_string_t;

typedef struct {
  shortener_manager_tuple2_string_string_t *ptr;
  size_t len;
} shortener_manager_list_tuple2_string_string_t;

typedef struct {
  shortener_manager_string_t *ptr;
  size_t len;
} shortener_manager_list_string_t;

typedef struct {
  bool is_some;
  shortener_manager_string_t val;
} shortener_manager_option_string_t;

typedef struct {
  shortener_manager_string_t id;
  shortener_manager_string_t name;
  shortener_manager_string_t version;
} golem_shortener_manager_api_worker_t;

typedef struct {
  bool is_err;
  union {
    shortener_manager_string_t ok;
    shortener_manager_string_t err;
  } val;
} shortener_manager_result_string_string_t;

typedef struct {
  golem_shortener_manager_api_worker_t *ptr;
  size_t len;
} shortener_manager_list_golem_shortener_manager_api_worker_t;

// Imported Functions from `wasi:cli/environment`
// Get the POSIX-style environment variables.
// 
// Each environment variable is provided as a pair of string variable names
// and string value.
// 
// Morally, these are a value import, but until value imports are available
// in the component model, this import function should return the same
// values each time it is called.
void wasi_cli_environment_get_environment(shortener_manager_list_tuple2_string_string_t *ret);
// Get the POSIX-style arguments to the program.
void wasi_cli_environment_get_arguments(shortener_manager_list_string_t *ret);
// Return a path that programs should use as their initial current working
// directory, interpreting `.` as shorthand for this.
void wasi_cli_environment_initial_cwd(shortener_manager_option_string_t *ret);

// Exported Functions from `golem-shortener:manager/api`
void exports_golem_shortener_manager_api_hello(shortener_manager_string_t *ret);
void exports_golem_shortener_manager_api_spawn(shortener_manager_string_t *url, shortener_manager_result_string_string_t *ret);
void exports_golem_shortener_manager_api_get_workers(shortener_manager_list_golem_shortener_manager_api_worker_t *ret);

// Helper Functions

void shortener_manager_tuple2_string_string_free(shortener_manager_tuple2_string_string_t *ptr);
void shortener_manager_list_tuple2_string_string_free(shortener_manager_list_tuple2_string_string_t *ptr);
void shortener_manager_list_string_free(shortener_manager_list_string_t *ptr);
void shortener_manager_option_string_free(shortener_manager_option_string_t *ptr);
void golem_shortener_manager_api_worker_free(golem_shortener_manager_api_worker_t *ptr);
void shortener_manager_result_string_string_free(shortener_manager_result_string_string_t *ptr);
void shortener_manager_list_golem_shortener_manager_api_worker_free(shortener_manager_list_golem_shortener_manager_api_worker_t *ptr);
void shortener_manager_string_set(shortener_manager_string_t *ret, const char*s);
void shortener_manager_string_dup(shortener_manager_string_t *ret, const char*s);
void shortener_manager_string_free(shortener_manager_string_t *ret);

#ifdef __cplusplus
}
#endif
#endif
