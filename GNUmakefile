MANDOC ?= mandoc

default: nanoidgen

all: public/man.pdf public/man/nanoid.3.html public/man/nanoidgen.1.html \
     public/openbsd/man.pdf public/openbsd/man/nanoid.3.html nanoidgen

clean:
	rm -r public nanoidgen

.PHONY: default all clean

public:
	mkdir -p $@

public/man: public
	mkdir -p $@

public/man.pdf: nanoid.3 nanoidgen.1 public
	$(MANDOC) -T pdf nanoid.3 nanoidgen.1 > $@

public/man/%.html: % public/man
	$(MANDOC) -T html $< > $@

public/openbsd: public
	mkdir -p $@

public/openbsd/man: public/openbsd
	mkdir -p $@

public/openbsd/man.pdf: openbsd/nanoid.3 nanoidgen.1 public/openbsd
	$(MANDOC) -T pdf openbsd/nanoid.3 nanoidgen.1 > $@

public/openbsd/man/%.html: openbsd/% public/openbsd/man
	$(MANDOC) -T html $< > $@
