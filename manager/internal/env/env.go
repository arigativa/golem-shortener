package env

import (
	"github.com/arigativa/golem-shortener/manager/internal/bindgen/shortener_manager"
	"os"
	"strings"
)

var envVars map[string]string

func init() {
	stdEnvs := os.Environ()
	for _, env := range stdEnvs {
		envArr := strings.SplitN(env, "=", 2)
		if len(envArr) == 2 {
			envVars[envArr[0]] = envArr[1]
		}
	}
	envList := shortener_manager.WasiCliEnvironmentGetEnvironment()
	for _, env := range envList {
		envVars[env.F0] = env.F1
	}
}

func GetOrElse(key string, def string) string {
	if val, ok := envVars[key]; ok {
		return val
	}
	return def
}

func All() map[string]string {
	return envVars
}
