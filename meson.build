project('password-cli-manager', 'c',
        default_options : ['c_std=c2x'])

cflags = ['-Wall', '-Wextra', '-Wdouble-promotion', '-Wformat-security', '-Wformat-type-confusion',  
	  '-Winit-self', '-Wswitch-default', '-Wstrict-overflow=4', '-Walloca', '-Wshadow -pedantic',
	  '-Wcast-qual', '-Wconversion', '-Wdate-time', '-Wstrict-prototypes', '-Wmissing-prototypes',
	  '-Winvalid-pch', '-Wmissing-variable-declarations', '-Wunreachable-code-aggressive',
	  '-Wextra-semi-stmt', '-Wused-but-marked-unused', '-Wcast-align', '-Wdocumentation']

executable('passcliman', 'src/info.c', 
                         'src/main.c',
                         'src/parse_input.c',
                         'src/parse_wrapper.c',
                         'src/password.c',
                         'src/utility.c')
