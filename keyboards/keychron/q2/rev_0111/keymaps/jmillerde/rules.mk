VIA_ENABLE = no
CONSOLE_ENABLE = yes

# Link our user defined RGB_MARTIX code if the setting is enabled
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif