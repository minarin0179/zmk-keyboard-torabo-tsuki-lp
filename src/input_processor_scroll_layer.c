/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_input_processor_scroll_layer

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <drivers/input_processor.h>
#include <zephyr/dt-bindings/input/input-event-codes.h>
#include <zmk/keymap.h>
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static int scroll_layer_handle_event(const struct device *dev, struct input_event *event,
                                     uint32_t param1, uint32_t param2,
                                     struct zmk_input_processor_state *state) {
    if (event->type != INPUT_EV_REL) {
        return ZMK_INPUT_PROC_CONTINUE;
    }

    if (!zmk_keymap_layer_active(zmk_keymap_layer_index_to_id(param1))) {
        return ZMK_INPUT_PROC_CONTINUE;
    }

    if (event->code == INPUT_REL_X) {
        event->code = INPUT_REL_HWHEEL;
    } else if (event->code == INPUT_REL_Y) {
        event->code = INPUT_REL_WHEEL;
    }

    return ZMK_INPUT_PROC_CONTINUE;
}

static const struct zmk_input_processor_driver_api scroll_layer_driver_api = {
    .handle_event = scroll_layer_handle_event,
};

#define SCROLL_LAYER_INST(n)                                                                       \
    DEVICE_DT_INST_DEFINE(n, NULL, NULL, NULL, NULL, POST_KERNEL,                                 \
                          CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &scroll_layer_driver_api);

DT_INST_FOREACH_STATUS_OKAY(SCROLL_LAYER_INST)
