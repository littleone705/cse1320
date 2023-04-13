TARGET_EXEC := monster_map

BUILD_DIR := ./build
SRC_DIRS := ./src
LDLIBS := -lm

SRCS := $(wildcard $(SRC_DIRS)/*.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

RELEASE := $(BUILD_DIR)/$(TARGET_EXEC)

$(RELEASE): $(OBJS)
		$(CC) $(OBJS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.c.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)