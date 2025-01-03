MANDOC ?= mandoc

default: nanoidgen

all: default pub/man.pdf pub/man/nanoid.3.html pub/man/nanoidgen.1.html \
     pub/openbsd/man.pdf pub/openbsd/man/nanoid.3.html

pub:
	mkdir -p $@

pub/man: pub
	mkdir -p $@

pub/man.pdf: nanoid.3 nanoidgen.1 pub
	$(MANDOC) -T pdf nanoid.3 nanoidgen.1 > $@

pub/man/%.html: % pub/man
	$(MANDOC) -T html $< > $@

pub/openbsd: pub
	mkdir -p $@

pub/openbsd/man: pub/openbsd
	mkdir -p $@

pub/openbsd/man.pdf: openbsd/nanoid.3 nanoidgen.1 pub/openbsd
	$(MANDOC) -T pdf openbsd/nanoid.3 nanoidgen.1 > $@

pub/openbsd/man/%.html: openbsd/% pub/openbsd/man
	$(MANDOC) -T html $< > $@
