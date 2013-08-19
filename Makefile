MODULES := S1-sharedCode S2-generator S3-algorithm S4-collector

all:
	@$(foreach MODULE,$(MODULES), cd $(MODULE); make; cd ../;)

clean:
	@$(foreach MODULE,$(MODULES), cd $(MODULE); make clean; cd ../;)
