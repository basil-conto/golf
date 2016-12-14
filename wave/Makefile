CFLAGS += -w
LDLIBS += -lm

srcext := .c
srcs   := wave
waves  := helix long short
subs   :=     3    6     7
prebin := wave-

srcs   := $(addsuffix $(srcext), $(srcs))
confs  := $(join $(waves), $(addprefix ., $(subs)))

define wave-rule-template =
$(prebin)$(1): CPPFLAGS += -DN=$(2)
$(prebin)$(1): $$(srcs)
	$$(LINK$(srcext)) $$^ $$(LDLIBS) $$(OUTPUT_OPTION)

.PHONY: clean-$(1)
clean-$(1):
	$(RM) $(1)
endef

make-wave = $(call wave-rule-template,$(firstword $(1)),$(lastword $(1)))

$(foreach conf, $(confs), $(eval $(call make-wave, $(subst ., ,$(conf)))))

.PHONY: clean
clean:
	$(RM) $(addprefix $(prebin), $(waves))
