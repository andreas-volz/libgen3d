AC_DEFUN([AX_EXTRA_DIST],
[
AC_MSG_NOTICE([adding custom dist support])
AM_CONDITIONAL(USING_AX_EXTRA_DIST, [true])
AX_ADD_AM_MACRO([[
EXTRA_SRC_DISTS =
EXTRA_BIN_DISTS =
dist-src-extra:
        @echo \"Making custom src targets...\"
        @cd \$(top_builddir); \\
        list='\$(EXTRA_SRC_DISTS)'; \\
        for dist in \$\$list; do \\
            \$(MAKE) \$(AM_MAKEFLAGS) dist-\$\$dist; \\
        done

dist-src: dist-all dist-src-extra


dist-bin:
        @echo \"Making custom binary targets...\"
        @cd \$(top_builddir); \\
        list='\$(EXTRA_BIN_DISTS)'; \\
        for dist in \$\$list; do \\
            \$(MAKE) \$(AM_MAKEFLAGS) dist-\$\$dist; \\
        done

all-dist dist2 dist-all2: dist-src dist-bin

all-dist-check dist2-check dist-all-check: dist-check dist-src-extra dist-bin
]])
])# AX_EXTRA_DIST
