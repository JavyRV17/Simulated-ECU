idf_component_register(
    SRCS 
        "Dio.c"
        "Dio_Cfg.c"
    INCLUDE_DIRS "."
    REQUIRES 
        esp_driver_gpio
        base
)