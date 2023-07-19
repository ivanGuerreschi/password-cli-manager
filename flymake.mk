.PHONY: check-syntax

check-syntax:
	$(CC) -I $(top_srcdir)/lib -I $(top_srcdir)/src -I $(top_srcdir)/test -Wall -Werror -o /dev/null -S ${CHK_SOURCES} || true
