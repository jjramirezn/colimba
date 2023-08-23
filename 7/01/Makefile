include ../../Makefile

package: build/upper build/lower build/invalid

build/lower: ${SRCS} build
	$(CC) $(CFLAGS) -o build/lower $(SRCS)

build/upper: ${SRCS} build/lower
	cp build/lower build/upper

build/invalid: ${SRCS} build/lower
	cp build/lower build/invalid
