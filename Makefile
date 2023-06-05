
TARGET = drumgirl
TYPE = ps-exe

SRCS = third_party/nugget/common/crt0/crt0.s src/main.c src/mesh.c src/psx.c src/sprite.c

CPPFLAGS += -Ithird_party/psyq-iwyu/include
LDFLAGS += -Lthird_party/psyq/lib
LDFLAGS += -Wl,--start-group
LDFLAGS += -lapi
LDFLAGS += -lc
LDFLAGS += -lc2
LDFLAGS += -lcard
LDFLAGS += -lcd
LDFLAGS += -lcomb
LDFLAGS += -lds
LDFLAGS += -letc
LDFLAGS += -lgpu
LDFLAGS += -lgs
LDFLAGS += -lgte
LDFLAGS += -lgun
LDFLAGS += -lhmd
LDFLAGS += -lmath
LDFLAGS += -lmcrd
LDFLAGS += -lmcx
LDFLAGS += -lpad
LDFLAGS += -lpress
LDFLAGS += -lsio
LDFLAGS += -lsnd
LDFLAGS += -lspu
LDFLAGS += -ltap
LDFLAGS += -Wl,--end-group

include third_party/nugget/common.mk

buildcd:
	mkpsxiso -o drumgirl.iso -y cd\cuesheet.xml

runduck:
	C:\duckstation-windows-x64-release\duckstation-qt-x64-ReleaseLTCG.exe drumgirl.iso

runpcsx:
	pcsx-redux.exe -stdout -iso drumgirl.iso