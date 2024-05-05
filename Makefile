TASK_NAME ?= 


TASK_DIR := task_$(TASK_NAME)
SOURCE_FILE := $(TASK_DIR)/source.cpp
TESTS_DIR := $(TASK_DIR)/tests


check_task_selected:
	@if [ -z "$(TASK_NAME)" ]; then \
		echo "No TASK_NAME specified for target!"; \
		exit 1; \
	fi
	@echo Running with task name $(TASK_NAME)


create_dirs: check_task_selected 
	mkdir -p $(TASK_DIR)
	mkdir -p $(TESTS_DIR)


create_source_files: create_dirs check_task_selected
	touch $(SOURCE_FILE)


create_test_files: create_dirs check_task_selected
	cp template_test_.py $(TESTS_DIR)/test_via_subprocess.py

create_invoke_file: create_dirs check_task_selected
	cp invoke_template.py $(TASK_DIR)/tasks.py


create: check_task_selected create_source_files create_test_files create_invoke_file

remove:
	rm -rf $(TASK_DIR)


.PHONY: all create_dirs create_source_file create_test_files clean
.DEFAULT_GOAL := create

