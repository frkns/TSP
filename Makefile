all:
	@echo "Running on sample input file\n"; \
	for src in *.cc; do \
		echo "==> $$src"; \
		python checker.py $$src < in; \
		echo; \
	done

