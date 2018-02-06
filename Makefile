all:
	if test -d cpp; then $(MAKE) -C cpp; fi
	if test -d StreamIt; then $(MAKE) -C StreamIt; fi
	if test -d SG; then $(MAKE) -C SG; fi

clean:
	if test -d cpp; then $(MAKE) -C cpp clean; fi
	if test -d StreamIt; then $(MAKE) -C StreamIt clean; fi
	if test -d SG; then $(MAKE) -C SG clean; fi

test:
	$(MAKE) -C cpp test; fi
	$(MAKE) -C StreamIt test; fi
	$(MAKE) -C SG test; fi
	cat ./*.txt | grep '^user\|-' > final_user.txt
	cat ./*.txt > final_all.txt

