#pragma once

#include <memory>
#include <spdlog/spdlog.h>

class logger final {
public:
  static spdlog::logger& get_logger(void) {
    static std::shared_ptr<spdlog::logger> logger;
    if (!logger) {
#if 1
      logger = spdlog::rotating_logger_mt("karabiner_grabber", "/var/log/karabiner_grabber_log", 1024 * 1024, 3, true);
#else
      logger = spdlog::stdout_logger_mt("karabiner_grabber", true);
#endif
    }
    return *logger;
  }
};