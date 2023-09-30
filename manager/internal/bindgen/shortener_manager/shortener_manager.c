// Generated by `wit-bindgen` 0.11.0. DO NOT EDIT!
#include "shortener_manager.h"


__attribute__((__import_module__("wasi:cli/environment"), __import_name__("get-environment")))
void __wasm_import_wasi_cli_environment_get_environment(int32_t);

__attribute__((__import_module__("wasi:cli/environment"), __import_name__("get-arguments")))
void __wasm_import_wasi_cli_environment_get_arguments(int32_t);

__attribute__((__import_module__("wasi:cli/environment"), __import_name__("initial-cwd")))
void __wasm_import_wasi_cli_environment_initial_cwd(int32_t);
__attribute__((__weak__, __export_name__("cabi_post_golem-shortener:manager/api#hello")))
void __wasm_export_exports_golem_shortener_manager_api_hello_post_return(int32_t arg0) {
  if ((*((int32_t*) (arg0 + 4))) > 0) {
    free((void*) (*((int32_t*) (arg0 + 0))));
  }
}
__attribute__((__weak__, __export_name__("cabi_post_golem-shortener:manager/api#spawn")))
void __wasm_export_exports_golem_shortener_manager_api_spawn_post_return(int32_t arg0) {
  switch ((int32_t) (int32_t) (*((uint8_t*) (arg0 + 0)))) {
    case 0: {
      if ((*((int32_t*) (arg0 + 8))) > 0) {
        free((void*) (*((int32_t*) (arg0 + 4))));
      }
      break;
    }
    case 1: {
      if ((*((int32_t*) (arg0 + 8))) > 0) {
        free((void*) (*((int32_t*) (arg0 + 4))));
      }
      break;
    }
  }
}
__attribute__((__weak__, __export_name__("cabi_post_golem-shortener:manager/api#get-workers")))
void __wasm_export_exports_golem_shortener_manager_api_get_workers_post_return(int32_t arg0) {
  int32_t ptr = *((int32_t*) (arg0 + 0));
  int32_t len = *((int32_t*) (arg0 + 4));
  for (int32_t i = 0; i < len; i++) {
    int32_t base = ptr + i * 24;
    (void) base;
    if ((*((int32_t*) (base + 4))) > 0) {
      free((void*) (*((int32_t*) (base + 0))));
    }
    if ((*((int32_t*) (base + 12))) > 0) {
      free((void*) (*((int32_t*) (base + 8))));
    }
    if ((*((int32_t*) (base + 20))) > 0) {
      free((void*) (*((int32_t*) (base + 16))));
    }
  }
  if (len > 0) {
    free((void*) (ptr));
  }
}

__attribute__((__weak__, __export_name__("cabi_realloc")))
void *cabi_realloc(void *ptr, size_t old_size, size_t align, size_t new_size) {
  (void) old_size;
  if (new_size == 0) return (void*) align;
  void *ret = realloc(ptr, new_size);
  if (!ret) abort();
  return ret;
}

// Helper Functions

void shortener_manager_tuple2_string_string_free(shortener_manager_tuple2_string_string_t *ptr) {
  shortener_manager_string_free(&ptr->f0);
  shortener_manager_string_free(&ptr->f1);
}

void shortener_manager_list_tuple2_string_string_free(shortener_manager_list_tuple2_string_string_t *ptr) {
  for (size_t i = 0; i < ptr->len; i++) {
    shortener_manager_tuple2_string_string_free(&ptr->ptr[i]);
  }
  if (ptr->len > 0) {
    free(ptr->ptr);
  }
}

void shortener_manager_list_string_free(shortener_manager_list_string_t *ptr) {
  for (size_t i = 0; i < ptr->len; i++) {
    shortener_manager_string_free(&ptr->ptr[i]);
  }
  if (ptr->len > 0) {
    free(ptr->ptr);
  }
}

void shortener_manager_option_string_free(shortener_manager_option_string_t *ptr) {
  if (ptr->is_some) {
    shortener_manager_string_free(&ptr->val);
  }
}

void golem_shortener_manager_api_worker_free(golem_shortener_manager_api_worker_t *ptr) {
  shortener_manager_string_free(&ptr->id);
  shortener_manager_string_free(&ptr->name);
  shortener_manager_string_free(&ptr->version);
}

void shortener_manager_result_string_string_free(shortener_manager_result_string_string_t *ptr) {
  if (!ptr->is_err) {
    shortener_manager_string_free(&ptr->val.ok);
  } else {
    shortener_manager_string_free(&ptr->val.err);
  }
}

void shortener_manager_list_golem_shortener_manager_api_worker_free(shortener_manager_list_golem_shortener_manager_api_worker_t *ptr) {
  for (size_t i = 0; i < ptr->len; i++) {
    golem_shortener_manager_api_worker_free(&ptr->ptr[i]);
  }
  if (ptr->len > 0) {
    free(ptr->ptr);
  }
}

void shortener_manager_string_set(shortener_manager_string_t *ret, const char*s) {
  ret->ptr = (char*) s;
  ret->len = strlen(s);
}

void shortener_manager_string_dup(shortener_manager_string_t *ret, const char*s) {
  ret->len = strlen(s);
  ret->ptr = cabi_realloc(NULL, 0, 1, ret->len * 1);
  memcpy(ret->ptr, s, ret->len * 1);
}

void shortener_manager_string_free(shortener_manager_string_t *ret) {
  if (ret->len > 0) {
    free(ret->ptr);
  }
  ret->ptr = NULL;
  ret->len = 0;
}

// Component Adapters

__attribute__((__aligned__(4)))
static uint8_t RET_AREA[12];

void wasi_cli_environment_get_environment(shortener_manager_list_tuple2_string_string_t *ret) {
  __attribute__((__aligned__(4)))
  uint8_t ret_area[8];
  int32_t ptr = (int32_t) &ret_area;
  __wasm_import_wasi_cli_environment_get_environment(ptr);
  *ret = (shortener_manager_list_tuple2_string_string_t) { (shortener_manager_tuple2_string_string_t*)(*((int32_t*) (ptr + 0))), (size_t)(*((int32_t*) (ptr + 4))) };
}

void wasi_cli_environment_get_arguments(shortener_manager_list_string_t *ret) {
  __attribute__((__aligned__(4)))
  uint8_t ret_area[8];
  int32_t ptr = (int32_t) &ret_area;
  __wasm_import_wasi_cli_environment_get_arguments(ptr);
  *ret = (shortener_manager_list_string_t) { (shortener_manager_string_t*)(*((int32_t*) (ptr + 0))), (size_t)(*((int32_t*) (ptr + 4))) };
}

void wasi_cli_environment_initial_cwd(shortener_manager_option_string_t *ret) {
  __attribute__((__aligned__(4)))
  uint8_t ret_area[12];
  int32_t ptr = (int32_t) &ret_area;
  __wasm_import_wasi_cli_environment_initial_cwd(ptr);
  shortener_manager_option_string_t option;
  switch ((int32_t) (*((uint8_t*) (ptr + 0)))) {
    case 0: {
      option.is_some = false;
      break;
    }
    case 1: {
      option.is_some = true;
      option.val = (shortener_manager_string_t) { (char*)(*((int32_t*) (ptr + 4))), (size_t)(*((int32_t*) (ptr + 8))) };
      break;
    }
  }
  *ret = option;
}

__attribute__((__export_name__("golem-shortener:manager/api#hello")))
int32_t __wasm_export_exports_golem_shortener_manager_api_hello(void) {
  shortener_manager_string_t ret;
  exports_golem_shortener_manager_api_hello(&ret);
  int32_t ptr = (int32_t) &RET_AREA;
  *((int32_t*)(ptr + 4)) = (int32_t) (ret).len;
  *((int32_t*)(ptr + 0)) = (int32_t) (ret).ptr;
  return ptr;
}

__attribute__((__export_name__("golem-shortener:manager/api#spawn")))
int32_t __wasm_export_exports_golem_shortener_manager_api_spawn(int32_t arg, int32_t arg0) {
  shortener_manager_string_t arg1 = (shortener_manager_string_t) { (char*)(arg), (size_t)(arg0) };
  shortener_manager_result_string_string_t ret;
  exports_golem_shortener_manager_api_spawn(&arg1, &ret);
  int32_t ptr = (int32_t) &RET_AREA;
  if ((ret).is_err) {
    const shortener_manager_string_t *payload2 = &(ret).val.err;*((int8_t*)(ptr + 0)) = 1;
    *((int32_t*)(ptr + 8)) = (int32_t) (*payload2).len;
    *((int32_t*)(ptr + 4)) = (int32_t) (*payload2).ptr;
  } else {
    const shortener_manager_string_t *payload = &(ret).val.ok;*((int8_t*)(ptr + 0)) = 0;
    *((int32_t*)(ptr + 8)) = (int32_t) (*payload).len;
    *((int32_t*)(ptr + 4)) = (int32_t) (*payload).ptr;
  }
  return ptr;
}

__attribute__((__export_name__("golem-shortener:manager/api#get-workers")))
int32_t __wasm_export_exports_golem_shortener_manager_api_get_workers(void) {
  shortener_manager_list_golem_shortener_manager_api_worker_t ret;
  exports_golem_shortener_manager_api_get_workers(&ret);
  int32_t ptr = (int32_t) &RET_AREA;
  *((int32_t*)(ptr + 4)) = (int32_t) (ret).len;
  *((int32_t*)(ptr + 0)) = (int32_t) (ret).ptr;
  return ptr;
}

extern void __component_type_object_force_link_shortener_manager(void);
void __component_type_object_force_link_shortener_manager_public_use_in_this_compilation_unit(void) {
  __component_type_object_force_link_shortener_manager();
}
