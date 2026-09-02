idf_component_register(
    SRCS 
       "Port.c"
       "Port_Cfg.c"

    INCLUDE_DIRS 
        "."

    REQUIRES 
        driver
        base
)