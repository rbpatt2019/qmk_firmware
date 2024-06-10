const rgblight_segment_t PROGMEM system_layer[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 8, HSV_ORANGE } );
const rgblight_segment_t PROGMEM apps_layer[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 8, HSV_BLUE } );
const rgblight_segment_t PROGMEM chrome_layer[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 8, HSV_CYAN } );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    system_layer,
    apps_layer,
    chrome_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));  //system_layer
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));  //apps_layer
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));  //chrome_layer
    return state;
}
