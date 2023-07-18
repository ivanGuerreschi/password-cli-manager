build_args = [
	'-Wall', '-Wextra', '-Wdouble-promotion', '-Wformat-security', '-Wformat-type-confusion',  
	'-Winit-self', '-Wswitch-default', '-Wstrict-overflow=4', '-Walloca', '-Wshadow', '-pedantic',
	'-Wcast-qual', '-Wconversion', '-Wdate-time', '-Wstrict-prototypes', '-Wmissing-prototypes',
	'-Winvalid-pch', '-Wmissing-variable-declarations', '-Wunreachable-code-aggressive',
	'-Wextra-semi-stmt', '-Wused-but-marked-unused', '-Wcast-align', '-Wdocumentation'
]

project_source_files = [
	'info.c',
  'password.c',
  'utility.c'
]


passwordlib = library(
  'password', 
  sources : project_source_files,
  install : true,
  c_args : build_args
)

passwordlib_dep = declare_dependency(
    include_directories : include_directories('.'), 
    link_with : passwordlib
)
