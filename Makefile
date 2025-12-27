input_file = example_input

all:
	@echo "Running on $(input_file)\n"; \
	for src in solutions/*.cc; do \
		echo "==> $$src"; \
		python checker.py $$src < $(input_file); \
		echo; \
	done
