{ pkgs }: {
	deps = [
		pkgs.valgrind
  pkgs.sudo
  pkgs.gitlab-shell
  pkgs.openssh_with_kerberos
  pkgs.python39Full
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}