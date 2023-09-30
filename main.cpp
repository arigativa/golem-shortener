#include <stdio.h>
#include <time.h>
#include <string>

#include "url_shortener.h"

int32_t main(void) {
    return 0;
}

static std::string url = "";
static unsigned long accessCount = 0;

bool isInitialized() {
    return url.length() != 0;
}

void exports_golem_template_api_set(url_shortener_string_t *value) {
    const auto requestNotEmpty = value->len != 0;
    if (!isInitialized() && requestNotEmpty) {
        url = std::move(std::string(value->ptr, value->len));
    }
}

void exports_golem_template_api_get(url_shortener_string_t *ret) {
    if (isInitialized()) {
        char* buf = new char[url.length()];
        std::copy(url.begin(), url.end(), buf);
        
        ret->ptr = buf;
        ret->len = url.length();
        
        accessCount += 1;
    } else {
        ret->ptr = nullptr;
        ret->len = 0;
    }
}

uint64_t exports_golem_template_api_stats(void) {
    return accessCount;
}