MODULES := sharedCode generator algorithm simulator collector printer

all:
	@$(foreach MODULE,$(MODULES), cd $(MODULE); make; cd ../;)

clean:
	@$(foreach MODULE,$(MODULES), cd $(MODULE); make clean; cd ../;)
