#include "keymap.h"

typedef enum QKeyCode {
    Q_KEY_CODE_UNMAPPED,
    Q_KEY_CODE_SHIFT,
    Q_KEY_CODE_SHIFT_R,
    Q_KEY_CODE_ALT,
    Q_KEY_CODE_ALT_R,
    Q_KEY_CODE_CTRL,
    Q_KEY_CODE_CTRL_R,
    Q_KEY_CODE_MENU,
    Q_KEY_CODE_ESC,
    Q_KEY_CODE_1,
    Q_KEY_CODE_2,
    Q_KEY_CODE_3,
    Q_KEY_CODE_4,
    Q_KEY_CODE_5,
    Q_KEY_CODE_6,
    Q_KEY_CODE_7,
    Q_KEY_CODE_8,
    Q_KEY_CODE_9,
    Q_KEY_CODE_0,
    Q_KEY_CODE_MINUS,
    Q_KEY_CODE_EQUAL,
    Q_KEY_CODE_BACKSPACE,
    Q_KEY_CODE_TAB,
    Q_KEY_CODE_Q,
    Q_KEY_CODE_W,
    Q_KEY_CODE_E,
    Q_KEY_CODE_R,
    Q_KEY_CODE_T,
    Q_KEY_CODE_Y,
    Q_KEY_CODE_U,
    Q_KEY_CODE_I,
    Q_KEY_CODE_O,
    Q_KEY_CODE_P,
    Q_KEY_CODE_BRACKET_LEFT,
    Q_KEY_CODE_BRACKET_RIGHT,
    Q_KEY_CODE_RET,
    Q_KEY_CODE_A,
    Q_KEY_CODE_S,
    Q_KEY_CODE_D,
    Q_KEY_CODE_F,
    Q_KEY_CODE_G,
    Q_KEY_CODE_H,
    Q_KEY_CODE_J,
    Q_KEY_CODE_K,
    Q_KEY_CODE_L,
    Q_KEY_CODE_SEMICOLON,
    Q_KEY_CODE_APOSTROPHE,
    Q_KEY_CODE_GRAVE_ACCENT,
    Q_KEY_CODE_BACKSLASH,
    Q_KEY_CODE_Z,
    Q_KEY_CODE_X,
    Q_KEY_CODE_C,
    Q_KEY_CODE_V,
    Q_KEY_CODE_B,
    Q_KEY_CODE_N,
    Q_KEY_CODE_M,
    Q_KEY_CODE_COMMA,
    Q_KEY_CODE_DOT,
    Q_KEY_CODE_SLASH,
    Q_KEY_CODE_ASTERISK,
    Q_KEY_CODE_SPC,
    Q_KEY_CODE_CAPS_LOCK,
    Q_KEY_CODE_F1,
    Q_KEY_CODE_F2,
    Q_KEY_CODE_F3,
    Q_KEY_CODE_F4,
    Q_KEY_CODE_F5,
    Q_KEY_CODE_F6,
    Q_KEY_CODE_F7,
    Q_KEY_CODE_F8,
    Q_KEY_CODE_F9,
    Q_KEY_CODE_F10,
    Q_KEY_CODE_NUM_LOCK,
    Q_KEY_CODE_SCROLL_LOCK,
    Q_KEY_CODE_KP_DIVIDE,
    Q_KEY_CODE_KP_MULTIPLY,
    Q_KEY_CODE_KP_SUBTRACT,
    Q_KEY_CODE_KP_ADD,
    Q_KEY_CODE_KP_ENTER,
    Q_KEY_CODE_KP_DECIMAL,
    Q_KEY_CODE_SYSRQ,
    Q_KEY_CODE_KP_0,
    Q_KEY_CODE_KP_1,
    Q_KEY_CODE_KP_2,
    Q_KEY_CODE_KP_3,
    Q_KEY_CODE_KP_4,
    Q_KEY_CODE_KP_5,
    Q_KEY_CODE_KP_6,
    Q_KEY_CODE_KP_7,
    Q_KEY_CODE_KP_8,
    Q_KEY_CODE_KP_9,
    Q_KEY_CODE_LESS,
    Q_KEY_CODE_F11,
    Q_KEY_CODE_F12,
    Q_KEY_CODE_PRINT,
    Q_KEY_CODE_HOME,
    Q_KEY_CODE_PGUP,
    Q_KEY_CODE_PGDN,
    Q_KEY_CODE_END,
    Q_KEY_CODE_LEFT,
    Q_KEY_CODE_UP,
    Q_KEY_CODE_DOWN,
    Q_KEY_CODE_RIGHT,
    Q_KEY_CODE_INSERT,
    Q_KEY_CODE_DELETE,
    Q_KEY_CODE_STOP,
    Q_KEY_CODE_AGAIN,
    Q_KEY_CODE_PROPS,
    Q_KEY_CODE_UNDO,
    Q_KEY_CODE_FRONT,
    Q_KEY_CODE_COPY,
    Q_KEY_CODE_OPEN,
    Q_KEY_CODE_PASTE,
    Q_KEY_CODE_FIND,
    Q_KEY_CODE_CUT,
    Q_KEY_CODE_LF,
    Q_KEY_CODE_HELP,
    Q_KEY_CODE_META_L,
    Q_KEY_CODE_META_R,
    Q_KEY_CODE_COMPOSE,
    Q_KEY_CODE_PAUSE,
    Q_KEY_CODE_RO,
    Q_KEY_CODE_HIRAGANA,
    Q_KEY_CODE_HENKAN,
    Q_KEY_CODE_YEN,
    Q_KEY_CODE_MUHENKAN,
    Q_KEY_CODE_KATAKANAHIRAGANA,
    Q_KEY_CODE_KP_COMMA,
    Q_KEY_CODE_KP_EQUALS,
    Q_KEY_CODE_POWER,
    Q_KEY_CODE_SLEEP,
    Q_KEY_CODE_WAKE,
    Q_KEY_CODE_AUDIONEXT,
    Q_KEY_CODE_AUDIOPREV,
    Q_KEY_CODE_AUDIOSTOP,
    Q_KEY_CODE_AUDIOPLAY,
    Q_KEY_CODE_AUDIOMUTE,
    Q_KEY_CODE_VOLUMEUP,
    Q_KEY_CODE_VOLUMEDOWN,
    Q_KEY_CODE_MEDIASELECT,
    Q_KEY_CODE_MAIL,
    Q_KEY_CODE_CALCULATOR,
    Q_KEY_CODE_COMPUTER,
    Q_KEY_CODE_AC_HOME,
    Q_KEY_CODE_AC_BACK,
    Q_KEY_CODE_AC_FORWARD,
    Q_KEY_CODE_AC_REFRESH,
    Q_KEY_CODE_AC_BOOKMARKS,
    Q_KEY_CODE__MAX,
} QKeyCode;

const uint16_t qemu_input_map_xorgevdev_to_qcode[533] = {
  [0x8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:8 -> linux:0 (KEY_RESERVED) -> qcode:Q_KEY_CODE_UNMAPPED (unmapped) */
  [0x9] = Q_KEY_CODE_ESC, /* xorgevdev:9 -> linux:1 (KEY_ESC) -> qcode:Q_KEY_CODE_ESC (esc) */
  [0xa] = Q_KEY_CODE_1, /* xorgevdev:10 -> linux:2 (KEY_1) -> qcode:Q_KEY_CODE_1 (1) */
  [0xb] = Q_KEY_CODE_2, /* xorgevdev:11 -> linux:3 (KEY_2) -> qcode:Q_KEY_CODE_2 (2) */
  [0xc] = Q_KEY_CODE_3, /* xorgevdev:12 -> linux:4 (KEY_3) -> qcode:Q_KEY_CODE_3 (3) */
  [0xd] = Q_KEY_CODE_4, /* xorgevdev:13 -> linux:5 (KEY_4) -> qcode:Q_KEY_CODE_4 (4) */
  [0xe] = Q_KEY_CODE_5, /* xorgevdev:14 -> linux:6 (KEY_5) -> qcode:Q_KEY_CODE_5 (5) */
  [0xf] = Q_KEY_CODE_6, /* xorgevdev:15 -> linux:7 (KEY_6) -> qcode:Q_KEY_CODE_6 (6) */
  [0x10] = Q_KEY_CODE_7, /* xorgevdev:16 -> linux:8 (KEY_7) -> qcode:Q_KEY_CODE_7 (7) */
  [0x11] = Q_KEY_CODE_8, /* xorgevdev:17 -> linux:9 (KEY_8) -> qcode:Q_KEY_CODE_8 (8) */
  [0x12] = Q_KEY_CODE_9, /* xorgevdev:18 -> linux:10 (KEY_9) -> qcode:Q_KEY_CODE_9 (9) */
  [0x13] = Q_KEY_CODE_0, /* xorgevdev:19 -> linux:11 (KEY_0) -> qcode:Q_KEY_CODE_0 (0) */
  [0x14] = Q_KEY_CODE_MINUS, /* xorgevdev:20 -> linux:12 (KEY_MINUS) -> qcode:Q_KEY_CODE_MINUS (minus) */
  [0x15] = Q_KEY_CODE_EQUAL, /* xorgevdev:21 -> linux:13 (KEY_EQUAL) -> qcode:Q_KEY_CODE_EQUAL (equal) */
  [0x16] = Q_KEY_CODE_BACKSPACE, /* xorgevdev:22 -> linux:14 (KEY_BACKSPACE) -> qcode:Q_KEY_CODE_BACKSPACE (backspace) */
  [0x17] = Q_KEY_CODE_TAB, /* xorgevdev:23 -> linux:15 (KEY_TAB) -> qcode:Q_KEY_CODE_TAB (tab) */
  [0x18] = Q_KEY_CODE_Q, /* xorgevdev:24 -> linux:16 (KEY_Q) -> qcode:Q_KEY_CODE_Q (q) */
  [0x19] = Q_KEY_CODE_W, /* xorgevdev:25 -> linux:17 (KEY_W) -> qcode:Q_KEY_CODE_W (w) */
  [0x1a] = Q_KEY_CODE_E, /* xorgevdev:26 -> linux:18 (KEY_E) -> qcode:Q_KEY_CODE_E (e) */
  [0x1b] = Q_KEY_CODE_R, /* xorgevdev:27 -> linux:19 (KEY_R) -> qcode:Q_KEY_CODE_R (r) */
  [0x1c] = Q_KEY_CODE_T, /* xorgevdev:28 -> linux:20 (KEY_T) -> qcode:Q_KEY_CODE_T (t) */
  [0x1d] = Q_KEY_CODE_Y, /* xorgevdev:29 -> linux:21 (KEY_Y) -> qcode:Q_KEY_CODE_Y (y) */
  [0x1e] = Q_KEY_CODE_U, /* xorgevdev:30 -> linux:22 (KEY_U) -> qcode:Q_KEY_CODE_U (u) */
  [0x1f] = Q_KEY_CODE_I, /* xorgevdev:31 -> linux:23 (KEY_I) -> qcode:Q_KEY_CODE_I (i) */
  [0x20] = Q_KEY_CODE_O, /* xorgevdev:32 -> linux:24 (KEY_O) -> qcode:Q_KEY_CODE_O (o) */
  [0x21] = Q_KEY_CODE_P, /* xorgevdev:33 -> linux:25 (KEY_P) -> qcode:Q_KEY_CODE_P (p) */
  [0x22] = Q_KEY_CODE_BRACKET_LEFT, /* xorgevdev:34 -> linux:26 (KEY_LEFTBRACE) -> qcode:Q_KEY_CODE_BRACKET_LEFT (bracket_left) */
  [0x23] = Q_KEY_CODE_BRACKET_RIGHT, /* xorgevdev:35 -> linux:27 (KEY_RIGHTBRACE) -> qcode:Q_KEY_CODE_BRACKET_RIGHT (bracket_right) */
  [0x24] = Q_KEY_CODE_RET, /* xorgevdev:36 -> linux:28 (KEY_ENTER) -> qcode:Q_KEY_CODE_RET (ret) */
  [0x25] = Q_KEY_CODE_CTRL, /* xorgevdev:37 -> linux:29 (KEY_LEFTCTRL) -> qcode:Q_KEY_CODE_CTRL (ctrl) */
  [0x26] = Q_KEY_CODE_A, /* xorgevdev:38 -> linux:30 (KEY_A) -> qcode:Q_KEY_CODE_A (a) */
  [0x27] = Q_KEY_CODE_S, /* xorgevdev:39 -> linux:31 (KEY_S) -> qcode:Q_KEY_CODE_S (s) */
  [0x28] = Q_KEY_CODE_D, /* xorgevdev:40 -> linux:32 (KEY_D) -> qcode:Q_KEY_CODE_D (d) */
  [0x29] = Q_KEY_CODE_F, /* xorgevdev:41 -> linux:33 (KEY_F) -> qcode:Q_KEY_CODE_F (f) */
  [0x2a] = Q_KEY_CODE_G, /* xorgevdev:42 -> linux:34 (KEY_G) -> qcode:Q_KEY_CODE_G (g) */
  [0x2b] = Q_KEY_CODE_H, /* xorgevdev:43 -> linux:35 (KEY_H) -> qcode:Q_KEY_CODE_H (h) */
  [0x2c] = Q_KEY_CODE_J, /* xorgevdev:44 -> linux:36 (KEY_J) -> qcode:Q_KEY_CODE_J (j) */
  [0x2d] = Q_KEY_CODE_K, /* xorgevdev:45 -> linux:37 (KEY_K) -> qcode:Q_KEY_CODE_K (k) */
  [0x2e] = Q_KEY_CODE_L, /* xorgevdev:46 -> linux:38 (KEY_L) -> qcode:Q_KEY_CODE_L (l) */
  [0x2f] = Q_KEY_CODE_SEMICOLON, /* xorgevdev:47 -> linux:39 (KEY_SEMICOLON) -> qcode:Q_KEY_CODE_SEMICOLON (semicolon) */
  [0x30] = Q_KEY_CODE_APOSTROPHE, /* xorgevdev:48 -> linux:40 (KEY_APOSTROPHE) -> qcode:Q_KEY_CODE_APOSTROPHE (apostrophe) */
  [0x31] = Q_KEY_CODE_GRAVE_ACCENT, /* xorgevdev:49 -> linux:41 (KEY_GRAVE) -> qcode:Q_KEY_CODE_GRAVE_ACCENT (grave_accent) */
  [0x32] = Q_KEY_CODE_SHIFT, /* xorgevdev:50 -> linux:42 (KEY_LEFTSHIFT) -> qcode:Q_KEY_CODE_SHIFT (shift) */
  [0x33] = Q_KEY_CODE_BACKSLASH, /* xorgevdev:51 -> linux:43 (KEY_BACKSLASH) -> qcode:Q_KEY_CODE_BACKSLASH (backslash) */
  [0x34] = Q_KEY_CODE_Z, /* xorgevdev:52 -> linux:44 (KEY_Z) -> qcode:Q_KEY_CODE_Z (z) */
  [0x35] = Q_KEY_CODE_X, /* xorgevdev:53 -> linux:45 (KEY_X) -> qcode:Q_KEY_CODE_X (x) */
  [0x36] = Q_KEY_CODE_C, /* xorgevdev:54 -> linux:46 (KEY_C) -> qcode:Q_KEY_CODE_C (c) */
  [0x37] = Q_KEY_CODE_V, /* xorgevdev:55 -> linux:47 (KEY_V) -> qcode:Q_KEY_CODE_V (v) */
  [0x38] = Q_KEY_CODE_B, /* xorgevdev:56 -> linux:48 (KEY_B) -> qcode:Q_KEY_CODE_B (b) */
  [0x39] = Q_KEY_CODE_N, /* xorgevdev:57 -> linux:49 (KEY_N) -> qcode:Q_KEY_CODE_N (n) */
  [0x3a] = Q_KEY_CODE_M, /* xorgevdev:58 -> linux:50 (KEY_M) -> qcode:Q_KEY_CODE_M (m) */
  [0x3b] = Q_KEY_CODE_COMMA, /* xorgevdev:59 -> linux:51 (KEY_COMMA) -> qcode:Q_KEY_CODE_COMMA (comma) */
  [0x3c] = Q_KEY_CODE_DOT, /* xorgevdev:60 -> linux:52 (KEY_DOT) -> qcode:Q_KEY_CODE_DOT (dot) */
  [0x3d] = Q_KEY_CODE_SLASH, /* xorgevdev:61 -> linux:53 (KEY_SLASH) -> qcode:Q_KEY_CODE_SLASH (slash) */
  [0x3e] = Q_KEY_CODE_SHIFT_R, /* xorgevdev:62 -> linux:54 (KEY_RIGHTSHIFT) -> qcode:Q_KEY_CODE_SHIFT_R (shift_r) */
  [0x3f] = Q_KEY_CODE_KP_MULTIPLY, /* xorgevdev:63 -> linux:55 (KEY_KPASTERISK) -> qcode:Q_KEY_CODE_KP_MULTIPLY (kp_multiply) */
  [0x40] = Q_KEY_CODE_ALT, /* xorgevdev:64 -> linux:56 (KEY_LEFTALT) -> qcode:Q_KEY_CODE_ALT (alt) */
  [0x41] = Q_KEY_CODE_SPC, /* xorgevdev:65 -> linux:57 (KEY_SPACE) -> qcode:Q_KEY_CODE_SPC (spc) */
  [0x42] = Q_KEY_CODE_CAPS_LOCK, /* xorgevdev:66 -> linux:58 (KEY_CAPSLOCK) -> qcode:Q_KEY_CODE_CAPS_LOCK (caps_lock) */
  [0x43] = Q_KEY_CODE_F1, /* xorgevdev:67 -> linux:59 (KEY_F1) -> qcode:Q_KEY_CODE_F1 (f1) */
  [0x44] = Q_KEY_CODE_F2, /* xorgevdev:68 -> linux:60 (KEY_F2) -> qcode:Q_KEY_CODE_F2 (f2) */
  [0x45] = Q_KEY_CODE_F3, /* xorgevdev:69 -> linux:61 (KEY_F3) -> qcode:Q_KEY_CODE_F3 (f3) */
  [0x46] = Q_KEY_CODE_F4, /* xorgevdev:70 -> linux:62 (KEY_F4) -> qcode:Q_KEY_CODE_F4 (f4) */
  [0x47] = Q_KEY_CODE_F5, /* xorgevdev:71 -> linux:63 (KEY_F5) -> qcode:Q_KEY_CODE_F5 (f5) */
  [0x48] = Q_KEY_CODE_F6, /* xorgevdev:72 -> linux:64 (KEY_F6) -> qcode:Q_KEY_CODE_F6 (f6) */
  [0x49] = Q_KEY_CODE_F7, /* xorgevdev:73 -> linux:65 (KEY_F7) -> qcode:Q_KEY_CODE_F7 (f7) */
  [0x4a] = Q_KEY_CODE_F8, /* xorgevdev:74 -> linux:66 (KEY_F8) -> qcode:Q_KEY_CODE_F8 (f8) */
  [0x4b] = Q_KEY_CODE_F9, /* xorgevdev:75 -> linux:67 (KEY_F9) -> qcode:Q_KEY_CODE_F9 (f9) */
  [0x4c] = Q_KEY_CODE_F10, /* xorgevdev:76 -> linux:68 (KEY_F10) -> qcode:Q_KEY_CODE_F10 (f10) */
  [0x4d] = Q_KEY_CODE_NUM_LOCK, /* xorgevdev:77 -> linux:69 (KEY_NUMLOCK) -> qcode:Q_KEY_CODE_NUM_LOCK (num_lock) */
  [0x4e] = Q_KEY_CODE_SCROLL_LOCK, /* xorgevdev:78 -> linux:70 (KEY_SCROLLLOCK) -> qcode:Q_KEY_CODE_SCROLL_LOCK (scroll_lock) */
  [0x4f] = Q_KEY_CODE_KP_7, /* xorgevdev:79 -> linux:71 (KEY_KP7) -> qcode:Q_KEY_CODE_KP_7 (kp_7) */
  [0x50] = Q_KEY_CODE_KP_8, /* xorgevdev:80 -> linux:72 (KEY_KP8) -> qcode:Q_KEY_CODE_KP_8 (kp_8) */
  [0x51] = Q_KEY_CODE_KP_9, /* xorgevdev:81 -> linux:73 (KEY_KP9) -> qcode:Q_KEY_CODE_KP_9 (kp_9) */
  [0x52] = Q_KEY_CODE_KP_SUBTRACT, /* xorgevdev:82 -> linux:74 (KEY_KPMINUS) -> qcode:Q_KEY_CODE_KP_SUBTRACT (kp_subtract) */
  [0x53] = Q_KEY_CODE_KP_4, /* xorgevdev:83 -> linux:75 (KEY_KP4) -> qcode:Q_KEY_CODE_KP_4 (kp_4) */
  [0x54] = Q_KEY_CODE_KP_5, /* xorgevdev:84 -> linux:76 (KEY_KP5) -> qcode:Q_KEY_CODE_KP_5 (kp_5) */
  [0x55] = Q_KEY_CODE_KP_6, /* xorgevdev:85 -> linux:77 (KEY_KP6) -> qcode:Q_KEY_CODE_KP_6 (kp_6) */
  [0x56] = Q_KEY_CODE_KP_ADD, /* xorgevdev:86 -> linux:78 (KEY_KPPLUS) -> qcode:Q_KEY_CODE_KP_ADD (kp_add) */
  [0x57] = Q_KEY_CODE_KP_1, /* xorgevdev:87 -> linux:79 (KEY_KP1) -> qcode:Q_KEY_CODE_KP_1 (kp_1) */
  [0x58] = Q_KEY_CODE_KP_2, /* xorgevdev:88 -> linux:80 (KEY_KP2) -> qcode:Q_KEY_CODE_KP_2 (kp_2) */
  [0x59] = Q_KEY_CODE_KP_3, /* xorgevdev:89 -> linux:81 (KEY_KP3) -> qcode:Q_KEY_CODE_KP_3 (kp_3) */
  [0x5a] = Q_KEY_CODE_KP_0, /* xorgevdev:90 -> linux:82 (KEY_KP0) -> qcode:Q_KEY_CODE_KP_0 (kp_0) */
  [0x5b] = Q_KEY_CODE_KP_DECIMAL, /* xorgevdev:91 -> linux:83 (KEY_KPDOT) -> qcode:Q_KEY_CODE_KP_DECIMAL (kp_decimal) */
  [0x5c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:92 -> linux:84 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x5d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:93 -> linux:85 (KEY_ZENKAKUHANKAKU) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x5e] = Q_KEY_CODE_LESS, /* xorgevdev:94 -> linux:86 (KEY_102ND) -> qcode:Q_KEY_CODE_LESS (less) */
  [0x5f] = Q_KEY_CODE_F11, /* xorgevdev:95 -> linux:87 (KEY_F11) -> qcode:Q_KEY_CODE_F11 (f11) */
  [0x60] = Q_KEY_CODE_F12, /* xorgevdev:96 -> linux:88 (KEY_F12) -> qcode:Q_KEY_CODE_F12 (f12) */
  [0x61] = Q_KEY_CODE_RO, /* xorgevdev:97 -> linux:89 (KEY_RO) -> qcode:Q_KEY_CODE_RO (ro) */
  [0x62] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:98 -> linux:90 (KEY_KATAKANA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x63] = Q_KEY_CODE_HIRAGANA, /* xorgevdev:99 -> linux:91 (KEY_HIRAGANA) -> qcode:Q_KEY_CODE_HIRAGANA (hiragana) */
  [0x64] = Q_KEY_CODE_HENKAN, /* xorgevdev:100 -> linux:92 (KEY_HENKAN) -> qcode:Q_KEY_CODE_HENKAN (henkan) */
  [0x65] = Q_KEY_CODE_KATAKANAHIRAGANA, /* xorgevdev:101 -> linux:93 (KEY_KATAKANAHIRAGANA) -> qcode:Q_KEY_CODE_KATAKANAHIRAGANA (katakanahiragana) */
  [0x66] = Q_KEY_CODE_MUHENKAN, /* xorgevdev:102 -> linux:94 (KEY_MUHENKAN) -> qcode:Q_KEY_CODE_MUHENKAN (muhenkan) */
  [0x67] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:103 -> linux:95 (KEY_KPJPCOMMA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x68] = Q_KEY_CODE_KP_ENTER, /* xorgevdev:104 -> linux:96 (KEY_KPENTER) -> qcode:Q_KEY_CODE_KP_ENTER (kp_enter) */
  [0x69] = Q_KEY_CODE_CTRL_R, /* xorgevdev:105 -> linux:97 (KEY_RIGHTCTRL) -> qcode:Q_KEY_CODE_CTRL_R (ctrl_r) */
  [0x6a] = Q_KEY_CODE_KP_DIVIDE, /* xorgevdev:106 -> linux:98 (KEY_KPSLASH) -> qcode:Q_KEY_CODE_KP_DIVIDE (kp_divide) */
  [0x6b] = Q_KEY_CODE_SYSRQ, /* xorgevdev:107 -> linux:99 (KEY_SYSRQ) -> qcode:Q_KEY_CODE_SYSRQ (sysrq) */
  [0x6c] = Q_KEY_CODE_ALT_R, /* xorgevdev:108 -> linux:100 (KEY_RIGHTALT) -> qcode:Q_KEY_CODE_ALT_R (alt_r) */
  [0x6d] = Q_KEY_CODE_LF, /* xorgevdev:109 -> linux:101 (KEY_LINEFEED) -> qcode:Q_KEY_CODE_LF (lf) */
  [0x6e] = Q_KEY_CODE_HOME, /* xorgevdev:110 -> linux:102 (KEY_HOME) -> qcode:Q_KEY_CODE_HOME (home) */
  [0x6f] = Q_KEY_CODE_UP, /* xorgevdev:111 -> linux:103 (KEY_UP) -> qcode:Q_KEY_CODE_UP (up) */
  [0x70] = Q_KEY_CODE_PGUP, /* xorgevdev:112 -> linux:104 (KEY_PAGEUP) -> qcode:Q_KEY_CODE_PGUP (pgup) */
  [0x71] = Q_KEY_CODE_LEFT, /* xorgevdev:113 -> linux:105 (KEY_LEFT) -> qcode:Q_KEY_CODE_LEFT (left) */
  [0x72] = Q_KEY_CODE_RIGHT, /* xorgevdev:114 -> linux:106 (KEY_RIGHT) -> qcode:Q_KEY_CODE_RIGHT (right) */
  [0x73] = Q_KEY_CODE_END, /* xorgevdev:115 -> linux:107 (KEY_END) -> qcode:Q_KEY_CODE_END (end) */
  [0x74] = Q_KEY_CODE_DOWN, /* xorgevdev:116 -> linux:108 (KEY_DOWN) -> qcode:Q_KEY_CODE_DOWN (down) */
  [0x75] = Q_KEY_CODE_PGDN, /* xorgevdev:117 -> linux:109 (KEY_PAGEDOWN) -> qcode:Q_KEY_CODE_PGDN (pgdn) */
  [0x76] = Q_KEY_CODE_INSERT, /* xorgevdev:118 -> linux:110 (KEY_INSERT) -> qcode:Q_KEY_CODE_INSERT (insert) */
  [0x77] = Q_KEY_CODE_DELETE, /* xorgevdev:119 -> linux:111 (KEY_DELETE) -> qcode:Q_KEY_CODE_DELETE (delete) */
  [0x78] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:120 -> linux:112 (KEY_MACRO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x79] = Q_KEY_CODE_AUDIOMUTE, /* xorgevdev:121 -> linux:113 (KEY_MUTE) -> qcode:Q_KEY_CODE_AUDIOMUTE (audiomute) */
  [0x7a] = Q_KEY_CODE_VOLUMEDOWN, /* xorgevdev:122 -> linux:114 (KEY_VOLUMEDOWN) -> qcode:Q_KEY_CODE_VOLUMEDOWN (volumedown) */
  [0x7b] = Q_KEY_CODE_VOLUMEUP, /* xorgevdev:123 -> linux:115 (KEY_VOLUMEUP) -> qcode:Q_KEY_CODE_VOLUMEUP (volumeup) */
  [0x7c] = Q_KEY_CODE_POWER, /* xorgevdev:124 -> linux:116 (KEY_POWER) -> qcode:Q_KEY_CODE_POWER (power) */
  [0x7d] = Q_KEY_CODE_KP_EQUALS, /* xorgevdev:125 -> linux:117 (KEY_KPEQUAL) -> qcode:Q_KEY_CODE_KP_EQUALS (kp_equals) */
  [0x7e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:126 -> linux:118 (KEY_KPPLUSMINUS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x7f] = Q_KEY_CODE_PAUSE, /* xorgevdev:127 -> linux:119 (KEY_PAUSE) -> qcode:Q_KEY_CODE_PAUSE (pause) */
  [0x80] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:128 -> linux:120 (KEY_SCALE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x81] = Q_KEY_CODE_KP_COMMA, /* xorgevdev:129 -> linux:121 (KEY_KPCOMMA) -> qcode:Q_KEY_CODE_KP_COMMA (kp_comma) */
  [0x82] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:130 -> linux:122 (KEY_HANGEUL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x83] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:131 -> linux:123 (KEY_HANJA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x84] = Q_KEY_CODE_YEN, /* xorgevdev:132 -> linux:124 (KEY_YEN) -> qcode:Q_KEY_CODE_YEN (yen) */
  [0x85] = Q_KEY_CODE_META_L, /* xorgevdev:133 -> linux:125 (KEY_LEFTMETA) -> qcode:Q_KEY_CODE_META_L (meta_l) */
  [0x86] = Q_KEY_CODE_META_R, /* xorgevdev:134 -> linux:126 (KEY_RIGHTMETA) -> qcode:Q_KEY_CODE_META_R (meta_r) */
  [0x87] = Q_KEY_CODE_COMPOSE, /* xorgevdev:135 -> linux:127 (KEY_COMPOSE) -> qcode:Q_KEY_CODE_COMPOSE (compose) */
  [0x88] = Q_KEY_CODE_STOP, /* xorgevdev:136 -> linux:128 (KEY_STOP) -> qcode:Q_KEY_CODE_STOP (stop) */
  [0x89] = Q_KEY_CODE_AGAIN, /* xorgevdev:137 -> linux:129 (KEY_AGAIN) -> qcode:Q_KEY_CODE_AGAIN (again) */
  [0x8a] = Q_KEY_CODE_PROPS, /* xorgevdev:138 -> linux:130 (KEY_PROPS) -> qcode:Q_KEY_CODE_PROPS (props) */
  [0x8b] = Q_KEY_CODE_UNDO, /* xorgevdev:139 -> linux:131 (KEY_UNDO) -> qcode:Q_KEY_CODE_UNDO (undo) */
  [0x8c] = Q_KEY_CODE_FRONT, /* xorgevdev:140 -> linux:132 (KEY_FRONT) -> qcode:Q_KEY_CODE_FRONT (front) */
  [0x8d] = Q_KEY_CODE_COPY, /* xorgevdev:141 -> linux:133 (KEY_COPY) -> qcode:Q_KEY_CODE_COPY (copy) */
  [0x8e] = Q_KEY_CODE_OPEN, /* xorgevdev:142 -> linux:134 (KEY_OPEN) -> qcode:Q_KEY_CODE_OPEN (open) */
  [0x8f] = Q_KEY_CODE_PASTE, /* xorgevdev:143 -> linux:135 (KEY_PASTE) -> qcode:Q_KEY_CODE_PASTE (paste) */
  [0x90] = Q_KEY_CODE_FIND, /* xorgevdev:144 -> linux:136 (KEY_FIND) -> qcode:Q_KEY_CODE_FIND (find) */
  [0x91] = Q_KEY_CODE_CUT, /* xorgevdev:145 -> linux:137 (KEY_CUT) -> qcode:Q_KEY_CODE_CUT (cut) */
  [0x92] = Q_KEY_CODE_HELP, /* xorgevdev:146 -> linux:138 (KEY_HELP) -> qcode:Q_KEY_CODE_HELP (help) */
  [0x93] = Q_KEY_CODE_MENU, /* xorgevdev:147 -> linux:139 (KEY_MENU) -> qcode:Q_KEY_CODE_MENU (menu) */
  [0x94] = Q_KEY_CODE_CALCULATOR, /* xorgevdev:148 -> linux:140 (KEY_CALC) -> qcode:Q_KEY_CODE_CALCULATOR (calculator) */
  [0x95] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:149 -> linux:141 (KEY_SETUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x96] = Q_KEY_CODE_SLEEP, /* xorgevdev:150 -> linux:142 (KEY_SLEEP) -> qcode:Q_KEY_CODE_SLEEP (sleep) */
  [0x97] = Q_KEY_CODE_WAKE, /* xorgevdev:151 -> linux:143 (KEY_WAKEUP) -> qcode:Q_KEY_CODE_WAKE (wake) */
  [0x98] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:152 -> linux:144 (KEY_FILE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x99] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:153 -> linux:145 (KEY_SENDFILE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:154 -> linux:146 (KEY_DELETEFILE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:155 -> linux:147 (KEY_XFER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:156 -> linux:148 (KEY_PROG1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:157 -> linux:149 (KEY_PROG2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:158 -> linux:150 (KEY_WWW) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x9f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:159 -> linux:151 (KEY_MSDOS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xa0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:160 -> linux:152 (KEY_SCREENLOCK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xa1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:161 -> linux:153 (KEY_DIRECTION) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xa2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:162 -> linux:154 (KEY_CYCLEWINDOWS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xa3] = Q_KEY_CODE_MAIL, /* xorgevdev:163 -> linux:155 (KEY_MAIL) -> qcode:Q_KEY_CODE_MAIL (mail) */
  [0xa4] = Q_KEY_CODE_AC_BOOKMARKS, /* xorgevdev:164 -> linux:156 (KEY_BOOKMARKS) -> qcode:Q_KEY_CODE_AC_BOOKMARKS (ac_bookmarks) */
  [0xa5] = Q_KEY_CODE_COMPUTER, /* xorgevdev:165 -> linux:157 (KEY_COMPUTER) -> qcode:Q_KEY_CODE_COMPUTER (computer) */
  [0xa6] = Q_KEY_CODE_AC_BACK, /* xorgevdev:166 -> linux:158 (KEY_BACK) -> qcode:Q_KEY_CODE_AC_BACK (ac_back) */
  [0xa7] = Q_KEY_CODE_AC_FORWARD, /* xorgevdev:167 -> linux:159 (KEY_FORWARD) -> qcode:Q_KEY_CODE_AC_FORWARD (ac_forward) */
  [0xa8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:168 -> linux:160 (KEY_CLOSECD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xa9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:169 -> linux:161 (KEY_EJECTCD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xaa] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:170 -> linux:162 (KEY_EJECTCLOSECD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xab] = Q_KEY_CODE_AUDIONEXT, /* xorgevdev:171 -> linux:163 (KEY_NEXTSONG) -> qcode:Q_KEY_CODE_AUDIONEXT (audionext) */
  [0xac] = Q_KEY_CODE_AUDIOPLAY, /* xorgevdev:172 -> linux:164 (KEY_PLAYPAUSE) -> qcode:Q_KEY_CODE_AUDIOPLAY (audioplay) */
  [0xad] = Q_KEY_CODE_AUDIOPREV, /* xorgevdev:173 -> linux:165 (KEY_PREVIOUSSONG) -> qcode:Q_KEY_CODE_AUDIOPREV (audioprev) */
  [0xae] = Q_KEY_CODE_AUDIOSTOP, /* xorgevdev:174 -> linux:166 (KEY_STOPCD) -> qcode:Q_KEY_CODE_AUDIOSTOP (audiostop) */
  [0xaf] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:175 -> linux:167 (KEY_RECORD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:176 -> linux:168 (KEY_REWIND) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:177 -> linux:169 (KEY_PHONE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:178 -> linux:170 (KEY_ISO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:179 -> linux:171 (KEY_CONFIG) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb4] = Q_KEY_CODE_AC_HOME, /* xorgevdev:180 -> linux:172 (KEY_HOMEPAGE) -> qcode:Q_KEY_CODE_AC_HOME (ac_home) */
  [0xb5] = Q_KEY_CODE_AC_REFRESH, /* xorgevdev:181 -> linux:173 (KEY_REFRESH) -> qcode:Q_KEY_CODE_AC_REFRESH (ac_refresh) */
  [0xb6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:182 -> linux:174 (KEY_EXIT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:183 -> linux:175 (KEY_MOVE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:184 -> linux:176 (KEY_EDIT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:185 -> linux:177 (KEY_SCROLLUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xba] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:186 -> linux:178 (KEY_SCROLLDOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xbb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:187 -> linux:179 (KEY_KPLEFTPAREN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xbc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:188 -> linux:180 (KEY_KPRIGHTPAREN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xbd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:189 -> linux:181 (KEY_NEW) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xbe] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:190 -> linux:182 (KEY_REDO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xbf] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:191 -> linux:183 (KEY_F13) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:192 -> linux:184 (KEY_F14) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:193 -> linux:185 (KEY_F15) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:194 -> linux:186 (KEY_F16) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:195 -> linux:187 (KEY_F17) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:196 -> linux:188 (KEY_F18) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:197 -> linux:189 (KEY_F19) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:198 -> linux:190 (KEY_F20) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:199 -> linux:191 (KEY_F21) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:200 -> linux:192 (KEY_F22) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xc9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:201 -> linux:193 (KEY_F23) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xca] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:202 -> linux:194 (KEY_F24) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xcb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:203 -> linux:195 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xcc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:204 -> linux:196 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xcd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:205 -> linux:197 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xce] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:206 -> linux:198 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xcf] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:207 -> linux:199 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:208 -> linux:200 (KEY_PLAYCD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:209 -> linux:201 (KEY_PAUSECD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:210 -> linux:202 (KEY_PROG3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:211 -> linux:203 (KEY_PROG4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:212 -> linux:204 (KEY_DASHBOARD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:213 -> linux:205 (KEY_SUSPEND) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:214 -> linux:206 (KEY_CLOSE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:215 -> linux:207 (KEY_PLAY) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:216 -> linux:208 (KEY_FASTFORWARD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xd9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:217 -> linux:209 (KEY_BASSBOOST) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xda] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:218 -> linux:210 (KEY_PRINT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xdb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:219 -> linux:211 (KEY_HP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xdc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:220 -> linux:212 (KEY_CAMERA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xdd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:221 -> linux:213 (KEY_SOUND) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xde] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:222 -> linux:214 (KEY_QUESTION) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xdf] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:223 -> linux:215 (KEY_EMAIL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:224 -> linux:216 (KEY_CHAT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:225 -> linux:217 (KEY_SEARCH) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:226 -> linux:218 (KEY_CONNECT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:227 -> linux:219 (KEY_FINANCE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:228 -> linux:220 (KEY_SPORT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:229 -> linux:221 (KEY_SHOP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:230 -> linux:222 (KEY_ALTERASE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:231 -> linux:223 (KEY_CANCEL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:232 -> linux:224 (KEY_BRIGHTNESSDOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:233 -> linux:225 (KEY_BRIGHTNESSUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xea] = Q_KEY_CODE_MEDIASELECT, /* xorgevdev:234 -> linux:226 (KEY_MEDIA) -> qcode:Q_KEY_CODE_MEDIASELECT (mediaselect) */
  [0xeb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:235 -> linux:227 (KEY_SWITCHVIDEOMODE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xec] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:236 -> linux:228 (KEY_KBDILLUMTOGGLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xed] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:237 -> linux:229 (KEY_KBDILLUMDOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xee] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:238 -> linux:230 (KEY_KBDILLUMUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xef] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:239 -> linux:231 (KEY_SEND) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:240 -> linux:232 (KEY_REPLY) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:241 -> linux:233 (KEY_FORWARDMAIL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:242 -> linux:234 (KEY_SAVE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:243 -> linux:235 (KEY_DOCUMENTS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:244 -> linux:236 (KEY_BATTERY) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:245 -> linux:237 (KEY_BLUETOOTH) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:246 -> linux:238 (KEY_WLAN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:247 -> linux:239 (KEY_UWB) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:248 -> linux:240 (KEY_UNKNOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:249 -> linux:241 (KEY_VIDEO_NEXT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfa] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:250 -> linux:242 (KEY_VIDEO_PREV) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:251 -> linux:243 (KEY_BRIGHTNESS_CYCLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:252 -> linux:244 (KEY_BRIGHTNESS_ZERO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:253 -> linux:245 (KEY_DISPLAY_OFF) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfe] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:254 -> linux:246 (KEY_WIMAX) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xff] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:255 -> linux:247 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x100] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:256 -> linux:248 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x101] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:257 -> linux:249 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x102] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:258 -> linux:250 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x103] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:259 -> linux:251 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x104] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:260 -> linux:252 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x105] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:261 -> linux:253 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x106] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:262 -> linux:254 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x107] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:263 -> linux:255 (unnamed) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x108] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:264 -> linux:256 (BTN_0) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x109] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:265 -> linux:257 (BTN_1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:266 -> linux:258 (BTN_2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:267 -> linux:259 (BTN_3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:268 -> linux:260 (BTN_4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:269 -> linux:261 (BTN_5) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:270 -> linux:262 (BTN_6) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x10f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:271 -> linux:263 (BTN_7) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x110] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:272 -> linux:264 (BTN_8) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x111] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:273 -> linux:265 (BTN_9) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x118] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:280 -> linux:272 (BTN_LEFT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x119] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:281 -> linux:273 (BTN_RIGHT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:282 -> linux:274 (BTN_MIDDLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:283 -> linux:275 (BTN_SIDE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:284 -> linux:276 (BTN_EXTRA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:285 -> linux:277 (BTN_FORWARD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:286 -> linux:278 (BTN_BACK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x11f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:287 -> linux:279 (BTN_TASK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x128] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:296 -> linux:288 (BTN_TRIGGER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x129] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:297 -> linux:289 (BTN_THUMB) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:298 -> linux:290 (BTN_THUMB2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:299 -> linux:291 (BTN_TOP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:300 -> linux:292 (BTN_TOP2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:301 -> linux:293 (BTN_PINKIE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:302 -> linux:294 (BTN_BASE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x12f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:303 -> linux:295 (BTN_BASE2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x130] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:304 -> linux:296 (BTN_BASE3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x131] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:305 -> linux:297 (BTN_BASE4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x132] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:306 -> linux:298 (BTN_BASE5) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x133] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:307 -> linux:299 (BTN_BASE6) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x137] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:311 -> linux:303 (BTN_DEAD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x138] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:312 -> linux:304 (BTN_A) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x139] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:313 -> linux:305 (BTN_B) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:314 -> linux:306 (BTN_C) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:315 -> linux:307 (BTN_X) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:316 -> linux:308 (BTN_Y) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:317 -> linux:309 (BTN_Z) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:318 -> linux:310 (BTN_TL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x13f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:319 -> linux:311 (BTN_TR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x140] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:320 -> linux:312 (BTN_TL2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x141] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:321 -> linux:313 (BTN_TR2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x142] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:322 -> linux:314 (BTN_SELECT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x143] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:323 -> linux:315 (BTN_START) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x144] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:324 -> linux:316 (BTN_MODE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x145] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:325 -> linux:317 (BTN_THUMBL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x146] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:326 -> linux:318 (BTN_THUMBR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x148] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:328 -> linux:320 (BTN_TOOL_PEN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x149] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:329 -> linux:321 (BTN_TOOL_RUBBER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:330 -> linux:322 (BTN_TOOL_BRUSH) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:331 -> linux:323 (BTN_TOOL_PENCIL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:332 -> linux:324 (BTN_TOOL_AIRBRUSH) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:333 -> linux:325 (BTN_TOOL_FINGER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:334 -> linux:326 (BTN_TOOL_MOUSE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x14f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:335 -> linux:327 (BTN_TOOL_LENS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x152] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:338 -> linux:330 (BTN_TOUCH) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x153] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:339 -> linux:331 (BTN_STYLUS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x154] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:340 -> linux:332 (BTN_STYLUS2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x155] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:341 -> linux:333 (BTN_TOOL_DOUBLETAP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x156] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:342 -> linux:334 (BTN_TOOL_TRIPLETAP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x157] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:343 -> linux:335 (BTN_TOOL_QUADTAP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x158] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:344 -> linux:336 (BTN_GEAR_DOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x159] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:345 -> linux:337 (BTN_GEAR_UP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x168] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:360 -> linux:352 (KEY_OK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x169] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:361 -> linux:353 (KEY_SELECT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:362 -> linux:354 (KEY_GOTO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:363 -> linux:355 (KEY_CLEAR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:364 -> linux:356 (KEY_POWER2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:365 -> linux:357 (KEY_OPTION) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:366 -> linux:358 (KEY_INFO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x16f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:367 -> linux:359 (KEY_TIME) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x170] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:368 -> linux:360 (KEY_VENDOR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x171] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:369 -> linux:361 (KEY_ARCHIVE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x172] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:370 -> linux:362 (KEY_PROGRAM) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x173] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:371 -> linux:363 (KEY_CHANNEL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x174] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:372 -> linux:364 (KEY_FAVORITES) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x175] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:373 -> linux:365 (KEY_EPG) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x176] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:374 -> linux:366 (KEY_PVR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x177] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:375 -> linux:367 (KEY_MHP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x178] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:376 -> linux:368 (KEY_LANGUAGE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x179] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:377 -> linux:369 (KEY_TITLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:378 -> linux:370 (KEY_SUBTITLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:379 -> linux:371 (KEY_ANGLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:380 -> linux:372 (KEY_ZOOM) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:381 -> linux:373 (KEY_MODE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:382 -> linux:374 (KEY_KEYBOARD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x17f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:383 -> linux:375 (KEY_SCREEN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x180] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:384 -> linux:376 (KEY_PC) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x181] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:385 -> linux:377 (KEY_TV) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x182] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:386 -> linux:378 (KEY_TV2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x183] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:387 -> linux:379 (KEY_VCR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x184] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:388 -> linux:380 (KEY_VCR2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x185] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:389 -> linux:381 (KEY_SAT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x186] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:390 -> linux:382 (KEY_SAT2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x187] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:391 -> linux:383 (KEY_CD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x188] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:392 -> linux:384 (KEY_TAPE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x189] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:393 -> linux:385 (KEY_RADIO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:394 -> linux:386 (KEY_TUNER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:395 -> linux:387 (KEY_PLAYER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:396 -> linux:388 (KEY_TEXT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:397 -> linux:389 (KEY_DVD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:398 -> linux:390 (KEY_AUX) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x18f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:399 -> linux:391 (KEY_MP3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x190] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:400 -> linux:392 (KEY_AUDIO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x191] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:401 -> linux:393 (KEY_VIDEO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x192] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:402 -> linux:394 (KEY_DIRECTORY) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x193] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:403 -> linux:395 (KEY_LIST) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x194] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:404 -> linux:396 (KEY_MEMO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x195] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:405 -> linux:397 (KEY_CALENDAR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x196] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:406 -> linux:398 (KEY_RED) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x197] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:407 -> linux:399 (KEY_GREEN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x198] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:408 -> linux:400 (KEY_YELLOW) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x199] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:409 -> linux:401 (KEY_BLUE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:410 -> linux:402 (KEY_CHANNELUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:411 -> linux:403 (KEY_CHANNELDOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:412 -> linux:404 (KEY_FIRST) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:413 -> linux:405 (KEY_LAST) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:414 -> linux:406 (KEY_AB) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x19f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:415 -> linux:407 (KEY_NEXT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:416 -> linux:408 (KEY_RESTART) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:417 -> linux:409 (KEY_SLOW) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:418 -> linux:410 (KEY_SHUFFLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:419 -> linux:411 (KEY_BREAK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:420 -> linux:412 (KEY_PREVIOUS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:421 -> linux:413 (KEY_DIGITS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:422 -> linux:414 (KEY_TEEN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:423 -> linux:415 (KEY_TWEN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:424 -> linux:416 (KEY_VIDEOPHONE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1a9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:425 -> linux:417 (KEY_GAMES) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1aa] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:426 -> linux:418 (KEY_ZOOMIN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ab] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:427 -> linux:419 (KEY_ZOOMOUT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ac] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:428 -> linux:420 (KEY_ZOOMRESET) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ad] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:429 -> linux:421 (KEY_WORDPROCESSOR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ae] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:430 -> linux:422 (KEY_EDITOR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1af] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:431 -> linux:423 (KEY_SPREADSHEET) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:432 -> linux:424 (KEY_GRAPHICSEDITOR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:433 -> linux:425 (KEY_PRESENTATION) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:434 -> linux:426 (KEY_DATABASE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:435 -> linux:427 (KEY_NEWS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:436 -> linux:428 (KEY_VOICEMAIL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:437 -> linux:429 (KEY_ADDRESSBOOK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:438 -> linux:430 (KEY_MESSENGER) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:439 -> linux:431 (KEY_DISPLAYTOGGLE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:440 -> linux:432 (KEY_SPELLCHECK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1b9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:441 -> linux:433 (KEY_LOGOFF) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ba] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:442 -> linux:434 (KEY_DOLLAR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1bb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:443 -> linux:435 (KEY_EURO) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1bc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:444 -> linux:436 (KEY_FRAMEBACK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1bd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:445 -> linux:437 (KEY_FRAMEFORWARD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1be] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:446 -> linux:438 (KEY_CONTEXT_MENU) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1bf] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:447 -> linux:439 (KEY_MEDIA_REPEAT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1c8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:456 -> linux:448 (KEY_DEL_EOL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1c9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:457 -> linux:449 (KEY_DEL_EOS) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ca] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:458 -> linux:450 (KEY_INS_LINE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1cb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:459 -> linux:451 (KEY_DEL_LINE) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1d8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:472 -> linux:464 (KEY_FN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1d9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:473 -> linux:465 (KEY_FN_ESC) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1da] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:474 -> linux:466 (KEY_FN_F1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1db] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:475 -> linux:467 (KEY_FN_F2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1dc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:476 -> linux:468 (KEY_FN_F3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1dd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:477 -> linux:469 (KEY_FN_F4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1de] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:478 -> linux:470 (KEY_FN_F5) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1df] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:479 -> linux:471 (KEY_FN_F6) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e0] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:480 -> linux:472 (KEY_FN_F7) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e1] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:481 -> linux:473 (KEY_FN_F8) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e2] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:482 -> linux:474 (KEY_FN_F9) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e3] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:483 -> linux:475 (KEY_FN_F10) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e4] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:484 -> linux:476 (KEY_FN_F11) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e5] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:485 -> linux:477 (KEY_FN_F12) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e6] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:486 -> linux:478 (KEY_FN_1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e7] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:487 -> linux:479 (KEY_FN_2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e8] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:488 -> linux:480 (KEY_FN_D) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1e9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:489 -> linux:481 (KEY_FN_E) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ea] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:490 -> linux:482 (KEY_FN_F) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1eb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:491 -> linux:483 (KEY_FN_S) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ec] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:492 -> linux:484 (KEY_FN_B) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1f9] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:505 -> linux:497 (KEY_BRL_DOT1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1fa] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:506 -> linux:498 (KEY_BRL_DOT2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1fb] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:507 -> linux:499 (KEY_BRL_DOT3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1fc] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:508 -> linux:500 (KEY_BRL_DOT4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1fd] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:509 -> linux:501 (KEY_BRL_DOT5) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1fe] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:510 -> linux:502 (KEY_BRL_DOT6) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x1ff] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:511 -> linux:503 (KEY_BRL_DOT7) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x200] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:512 -> linux:504 (KEY_BRL_DOT8) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x201] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:513 -> linux:505 (KEY_BRL_DOT9) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x202] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:514 -> linux:506 (KEY_BRL_DOT10) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x208] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:520 -> linux:512 (KEY_NUMERIC_0) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x209] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:521 -> linux:513 (KEY_NUMERIC_1) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20a] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:522 -> linux:514 (KEY_NUMERIC_2) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20b] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:523 -> linux:515 (KEY_NUMERIC_3) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20c] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:524 -> linux:516 (KEY_NUMERIC_4) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20d] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:525 -> linux:517 (KEY_NUMERIC_5) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20e] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:526 -> linux:518 (KEY_NUMERIC_6) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x20f] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:527 -> linux:519 (KEY_NUMERIC_7) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x210] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:528 -> linux:520 (KEY_NUMERIC_8) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x211] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:529 -> linux:521 (KEY_NUMERIC_9) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x212] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:530 -> linux:522 (KEY_NUMERIC_STAR) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x213] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:531 -> linux:523 (KEY_NUMERIC_POUND) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x214] = Q_KEY_CODE_UNMAPPED, /* xorgevdev:532 -> linux:524 (KEY_RFKILL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
};

const uint64_t qemu_input_map_xorgevdev_to_qcode_len = sizeof(qemu_input_map_xorgevdev_to_qcode)/sizeof(qemu_input_map_xorgevdev_to_qcode[0]);

const uint16_t qemu_input_map_qcode_to_atset1[Q_KEY_CODE__MAX] = {
  [Q_KEY_CODE_0] = 0xb, /* qcode:Q_KEY_CODE_0 (0) -> linux:11 (KEY_0) -> atset1:11 */
  [Q_KEY_CODE_1] = 0x2, /* qcode:Q_KEY_CODE_1 (1) -> linux:2 (KEY_1) -> atset1:2 */
  [Q_KEY_CODE_2] = 0x3, /* qcode:Q_KEY_CODE_2 (2) -> linux:3 (KEY_2) -> atset1:3 */
  [Q_KEY_CODE_3] = 0x4, /* qcode:Q_KEY_CODE_3 (3) -> linux:4 (KEY_3) -> atset1:4 */
  [Q_KEY_CODE_4] = 0x5, /* qcode:Q_KEY_CODE_4 (4) -> linux:5 (KEY_4) -> atset1:5 */
  [Q_KEY_CODE_5] = 0x6, /* qcode:Q_KEY_CODE_5 (5) -> linux:6 (KEY_5) -> atset1:6 */
  [Q_KEY_CODE_6] = 0x7, /* qcode:Q_KEY_CODE_6 (6) -> linux:7 (KEY_6) -> atset1:7 */
  [Q_KEY_CODE_7] = 0x8, /* qcode:Q_KEY_CODE_7 (7) -> linux:8 (KEY_7) -> atset1:8 */
  [Q_KEY_CODE_8] = 0x9, /* qcode:Q_KEY_CODE_8 (8) -> linux:9 (KEY_8) -> atset1:9 */
  [Q_KEY_CODE_9] = 0xa, /* qcode:Q_KEY_CODE_9 (9) -> linux:10 (KEY_9) -> atset1:10 */
  [Q_KEY_CODE_A] = 0x1e, /* qcode:Q_KEY_CODE_A (a) -> linux:30 (KEY_A) -> atset1:30 */
  [Q_KEY_CODE_AC_BACK] = 0xe06a, /* qcode:Q_KEY_CODE_AC_BACK (ac_back) -> linux:158 (KEY_BACK) -> atset1:57450 */
  [Q_KEY_CODE_AC_BOOKMARKS] = 0xe066, /* qcode:Q_KEY_CODE_AC_BOOKMARKS (ac_bookmarks) -> linux:156 (KEY_BOOKMARKS) -> atset1:57446 */
  [Q_KEY_CODE_AC_FORWARD] = 0xe069, /* qcode:Q_KEY_CODE_AC_FORWARD (ac_forward) -> linux:159 (KEY_FORWARD) -> atset1:57449 */
  [Q_KEY_CODE_AC_HOME] = 0xe032, /* qcode:Q_KEY_CODE_AC_HOME (ac_home) -> linux:172 (KEY_HOMEPAGE) -> atset1:57394 */
  [Q_KEY_CODE_AC_REFRESH] = 0xe067, /* qcode:Q_KEY_CODE_AC_REFRESH (ac_refresh) -> linux:173 (KEY_REFRESH) -> atset1:57447 */
  [Q_KEY_CODE_AGAIN] = 0xe005, /* qcode:Q_KEY_CODE_AGAIN (again) -> linux:129 (KEY_AGAIN) -> atset1:57349 */
  [Q_KEY_CODE_ALT] = 0x38, /* qcode:Q_KEY_CODE_ALT (alt) -> linux:56 (KEY_LEFTALT) -> atset1:56 */
  [Q_KEY_CODE_ALT_R] = 0xe038, /* qcode:Q_KEY_CODE_ALT_R (alt_r) -> linux:100 (KEY_RIGHTALT) -> atset1:57400 */
  [Q_KEY_CODE_APOSTROPHE] = 0x28, /* qcode:Q_KEY_CODE_APOSTROPHE (apostrophe) -> linux:40 (KEY_APOSTROPHE) -> atset1:40 */
  [Q_KEY_CODE_ASTERISK] = 0x37, /* qcode:Q_KEY_CODE_ASTERISK (kp_multiply) -> linux:55 (KEY_KPASTERISK) -> atset1:55 */
  [Q_KEY_CODE_AUDIOMUTE] = 0xe020, /* qcode:Q_KEY_CODE_AUDIOMUTE (audiomute) -> linux:113 (KEY_MUTE) -> atset1:57376 */
  [Q_KEY_CODE_AUDIONEXT] = 0xe019, /* qcode:Q_KEY_CODE_AUDIONEXT (audionext) -> linux:163 (KEY_NEXTSONG) -> atset1:57369 */
  [Q_KEY_CODE_AUDIOPLAY] = 0xe022, /* qcode:Q_KEY_CODE_AUDIOPLAY (audioplay) -> linux:164 (KEY_PLAYPAUSE) -> atset1:57378 */
  [Q_KEY_CODE_AUDIOPREV] = 0xe010, /* qcode:Q_KEY_CODE_AUDIOPREV (audioprev) -> linux:165 (KEY_PREVIOUSSONG) -> atset1:57360 */
  [Q_KEY_CODE_AUDIOSTOP] = 0xe024, /* qcode:Q_KEY_CODE_AUDIOSTOP (audiostop) -> linux:166 (KEY_STOPCD) -> atset1:57380 */
  [Q_KEY_CODE_B] = 0x30, /* qcode:Q_KEY_CODE_B (b) -> linux:48 (KEY_B) -> atset1:48 */
  [Q_KEY_CODE_BACKSLASH] = 0x2b, /* qcode:Q_KEY_CODE_BACKSLASH (backslash) -> linux:43 (KEY_BACKSLASH) -> atset1:43 */
  [Q_KEY_CODE_BACKSPACE] = 0xe, /* qcode:Q_KEY_CODE_BACKSPACE (backspace) -> linux:14 (KEY_BACKSPACE) -> atset1:14 */
  [Q_KEY_CODE_BRACKET_LEFT] = 0x1a, /* qcode:Q_KEY_CODE_BRACKET_LEFT (bracket_left) -> linux:26 (KEY_LEFTBRACE) -> atset1:26 */
  [Q_KEY_CODE_BRACKET_RIGHT] = 0x1b, /* qcode:Q_KEY_CODE_BRACKET_RIGHT (bracket_right) -> linux:27 (KEY_RIGHTBRACE) -> atset1:27 */
  [Q_KEY_CODE_C] = 0x2e, /* qcode:Q_KEY_CODE_C (c) -> linux:46 (KEY_C) -> atset1:46 */
  [Q_KEY_CODE_CALCULATOR] = 0xe021, /* qcode:Q_KEY_CODE_CALCULATOR (calculator) -> linux:140 (KEY_CALC) -> atset1:57377 */
  [Q_KEY_CODE_CAPS_LOCK] = 0x3a, /* qcode:Q_KEY_CODE_CAPS_LOCK (caps_lock) -> linux:58 (KEY_CAPSLOCK) -> atset1:58 */
  [Q_KEY_CODE_COMMA] = 0x33, /* qcode:Q_KEY_CODE_COMMA (comma) -> linux:51 (KEY_COMMA) -> atset1:51 */
  [Q_KEY_CODE_COMPOSE] = 0xe05d, /* qcode:Q_KEY_CODE_COMPOSE (compose) -> linux:127 (KEY_COMPOSE) -> atset1:57437 */
  [Q_KEY_CODE_COMPUTER] = 0xe06b, /* qcode:Q_KEY_CODE_COMPUTER (computer) -> linux:157 (KEY_COMPUTER) -> atset1:57451 */
  [Q_KEY_CODE_COPY] = 0xe078, /* qcode:Q_KEY_CODE_COPY (copy) -> linux:133 (KEY_COPY) -> atset1:57464 */
  [Q_KEY_CODE_CTRL] = 0x1d, /* qcode:Q_KEY_CODE_CTRL (ctrl) -> linux:29 (KEY_LEFTCTRL) -> atset1:29 */
  [Q_KEY_CODE_CTRL_R] = 0xe01d, /* qcode:Q_KEY_CODE_CTRL_R (ctrl_r) -> linux:97 (KEY_RIGHTCTRL) -> atset1:57373 */
  [Q_KEY_CODE_CUT] = 0xe03c, /* qcode:Q_KEY_CODE_CUT (cut) -> linux:137 (KEY_CUT) -> atset1:57404 */
  [Q_KEY_CODE_D] = 0x20, /* qcode:Q_KEY_CODE_D (d) -> linux:32 (KEY_D) -> atset1:32 */
  [Q_KEY_CODE_DELETE] = 0xe053, /* qcode:Q_KEY_CODE_DELETE (delete) -> linux:111 (KEY_DELETE) -> atset1:57427 */
  [Q_KEY_CODE_DOT] = 0x34, /* qcode:Q_KEY_CODE_DOT (dot) -> linux:52 (KEY_DOT) -> atset1:52 */
  [Q_KEY_CODE_DOWN] = 0xe050, /* qcode:Q_KEY_CODE_DOWN (down) -> linux:108 (KEY_DOWN) -> atset1:57424 */
  [Q_KEY_CODE_E] = 0x12, /* qcode:Q_KEY_CODE_E (e) -> linux:18 (KEY_E) -> atset1:18 */
  [Q_KEY_CODE_END] = 0xe04f, /* qcode:Q_KEY_CODE_END (end) -> linux:107 (KEY_END) -> atset1:57423 */
  [Q_KEY_CODE_EQUAL] = 0xd, /* qcode:Q_KEY_CODE_EQUAL (equal) -> linux:13 (KEY_EQUAL) -> atset1:13 */
  [Q_KEY_CODE_ESC] = 0x1, /* qcode:Q_KEY_CODE_ESC (esc) -> linux:1 (KEY_ESC) -> atset1:1 */
  [Q_KEY_CODE_F] = 0x21, /* qcode:Q_KEY_CODE_F (f) -> linux:33 (KEY_F) -> atset1:33 */
  [Q_KEY_CODE_F1] = 0x3b, /* qcode:Q_KEY_CODE_F1 (f1) -> linux:59 (KEY_F1) -> atset1:59 */
  [Q_KEY_CODE_F10] = 0x44, /* qcode:Q_KEY_CODE_F10 (f10) -> linux:68 (KEY_F10) -> atset1:68 */
  [Q_KEY_CODE_F11] = 0x57, /* qcode:Q_KEY_CODE_F11 (f11) -> linux:87 (KEY_F11) -> atset1:87 */
  [Q_KEY_CODE_F12] = 0x58, /* qcode:Q_KEY_CODE_F12 (f12) -> linux:88 (KEY_F12) -> atset1:88 */
  [Q_KEY_CODE_F2] = 0x3c, /* qcode:Q_KEY_CODE_F2 (f2) -> linux:60 (KEY_F2) -> atset1:60 */
  [Q_KEY_CODE_F3] = 0x3d, /* qcode:Q_KEY_CODE_F3 (f3) -> linux:61 (KEY_F3) -> atset1:61 */
  [Q_KEY_CODE_F4] = 0x3e, /* qcode:Q_KEY_CODE_F4 (f4) -> linux:62 (KEY_F4) -> atset1:62 */
  [Q_KEY_CODE_F5] = 0x3f, /* qcode:Q_KEY_CODE_F5 (f5) -> linux:63 (KEY_F5) -> atset1:63 */
  [Q_KEY_CODE_F6] = 0x40, /* qcode:Q_KEY_CODE_F6 (f6) -> linux:64 (KEY_F6) -> atset1:64 */
  [Q_KEY_CODE_F7] = 0x41, /* qcode:Q_KEY_CODE_F7 (f7) -> linux:65 (KEY_F7) -> atset1:65 */
  [Q_KEY_CODE_F8] = 0x42, /* qcode:Q_KEY_CODE_F8 (f8) -> linux:66 (KEY_F8) -> atset1:66 */
  [Q_KEY_CODE_F9] = 0x43, /* qcode:Q_KEY_CODE_F9 (f9) -> linux:67 (KEY_F9) -> atset1:67 */
  [Q_KEY_CODE_FIND] = 0xe041, /* qcode:Q_KEY_CODE_FIND (find) -> linux:136 (KEY_FIND) -> atset1:57409 */
  [Q_KEY_CODE_FRONT] = 0xe00c, /* qcode:Q_KEY_CODE_FRONT (front) -> linux:132 (KEY_FRONT) -> atset1:57356 */
  [Q_KEY_CODE_G] = 0x22, /* qcode:Q_KEY_CODE_G (g) -> linux:34 (KEY_G) -> atset1:34 */
  [Q_KEY_CODE_GRAVE_ACCENT] = 0x29, /* qcode:Q_KEY_CODE_GRAVE_ACCENT (grave_accent) -> linux:41 (KEY_GRAVE) -> atset1:41 */
  [Q_KEY_CODE_H] = 0x23, /* qcode:Q_KEY_CODE_H (h) -> linux:35 (KEY_H) -> atset1:35 */
  [Q_KEY_CODE_HELP] = 0xe075, /* qcode:Q_KEY_CODE_HELP (help) -> linux:138 (KEY_HELP) -> atset1:57461 */
  [Q_KEY_CODE_HENKAN] = 0x79, /* qcode:Q_KEY_CODE_HENKAN (henkan) -> linux:92 (KEY_HENKAN) -> atset1:121 */
  [Q_KEY_CODE_HIRAGANA] = 0x77, /* qcode:Q_KEY_CODE_HIRAGANA (hiragana) -> linux:91 (KEY_HIRAGANA) -> atset1:119 */
  [Q_KEY_CODE_HOME] = 0xe047, /* qcode:Q_KEY_CODE_HOME (home) -> linux:102 (KEY_HOME) -> atset1:57415 */
  [Q_KEY_CODE_I] = 0x17, /* qcode:Q_KEY_CODE_I (i) -> linux:23 (KEY_I) -> atset1:23 */
  [Q_KEY_CODE_INSERT] = 0xe052, /* qcode:Q_KEY_CODE_INSERT (insert) -> linux:110 (KEY_INSERT) -> atset1:57426 */
  [Q_KEY_CODE_J] = 0x24, /* qcode:Q_KEY_CODE_J (j) -> linux:36 (KEY_J) -> atset1:36 */
  [Q_KEY_CODE_K] = 0x25, /* qcode:Q_KEY_CODE_K (k) -> linux:37 (KEY_K) -> atset1:37 */
  [Q_KEY_CODE_KATAKANAHIRAGANA] = 0x70, /* qcode:Q_KEY_CODE_KATAKANAHIRAGANA (katakanahiragana) -> linux:93 (KEY_KATAKANAHIRAGANA) -> atset1:112 */
  [Q_KEY_CODE_KP_0] = 0x52, /* qcode:Q_KEY_CODE_KP_0 (kp_0) -> linux:82 (KEY_KP0) -> atset1:82 */
  [Q_KEY_CODE_KP_1] = 0x4f, /* qcode:Q_KEY_CODE_KP_1 (kp_1) -> linux:79 (KEY_KP1) -> atset1:79 */
  [Q_KEY_CODE_KP_2] = 0x50, /* qcode:Q_KEY_CODE_KP_2 (kp_2) -> linux:80 (KEY_KP2) -> atset1:80 */
  [Q_KEY_CODE_KP_3] = 0x51, /* qcode:Q_KEY_CODE_KP_3 (kp_3) -> linux:81 (KEY_KP3) -> atset1:81 */
  [Q_KEY_CODE_KP_4] = 0x4b, /* qcode:Q_KEY_CODE_KP_4 (kp_4) -> linux:75 (KEY_KP4) -> atset1:75 */
  [Q_KEY_CODE_KP_5] = 0x4c, /* qcode:Q_KEY_CODE_KP_5 (kp_5) -> linux:76 (KEY_KP5) -> atset1:76 */
  [Q_KEY_CODE_KP_6] = 0x4d, /* qcode:Q_KEY_CODE_KP_6 (kp_6) -> linux:77 (KEY_KP6) -> atset1:77 */
  [Q_KEY_CODE_KP_7] = 0x47, /* qcode:Q_KEY_CODE_KP_7 (kp_7) -> linux:71 (KEY_KP7) -> atset1:71 */
  [Q_KEY_CODE_KP_8] = 0x48, /* qcode:Q_KEY_CODE_KP_8 (kp_8) -> linux:72 (KEY_KP8) -> atset1:72 */
  [Q_KEY_CODE_KP_9] = 0x49, /* qcode:Q_KEY_CODE_KP_9 (kp_9) -> linux:73 (KEY_KP9) -> atset1:73 */
  [Q_KEY_CODE_KP_ADD] = 0x4e, /* qcode:Q_KEY_CODE_KP_ADD (kp_add) -> linux:78 (KEY_KPPLUS) -> atset1:78 */
  [Q_KEY_CODE_KP_COMMA] = 0x7e, /* qcode:Q_KEY_CODE_KP_COMMA (kp_comma) -> linux:121 (KEY_KPCOMMA) -> atset1:126 */
  [Q_KEY_CODE_KP_DECIMAL] = 0x53, /* qcode:Q_KEY_CODE_KP_DECIMAL (kp_decimal) -> linux:83 (KEY_KPDOT) -> atset1:83 */
  [Q_KEY_CODE_KP_DIVIDE] = 0xe035, /* qcode:Q_KEY_CODE_KP_DIVIDE (kp_divide) -> linux:98 (KEY_KPSLASH) -> atset1:57397 */
  [Q_KEY_CODE_KP_ENTER] = 0xe01c, /* qcode:Q_KEY_CODE_KP_ENTER (kp_enter) -> linux:96 (KEY_KPENTER) -> atset1:57372 */
  [Q_KEY_CODE_KP_EQUALS] = 0x59, /* qcode:Q_KEY_CODE_KP_EQUALS (kp_equals) -> linux:117 (KEY_KPEQUAL) -> atset1:89 */
  [Q_KEY_CODE_KP_MULTIPLY] = 0x37, /* qcode:Q_KEY_CODE_KP_MULTIPLY (kp_multiply) -> linux:55 (KEY_KPASTERISK) -> atset1:55 */
  [Q_KEY_CODE_KP_SUBTRACT] = 0x4a, /* qcode:Q_KEY_CODE_KP_SUBTRACT (kp_subtract) -> linux:74 (KEY_KPMINUS) -> atset1:74 */
  [Q_KEY_CODE_L] = 0x26, /* qcode:Q_KEY_CODE_L (l) -> linux:38 (KEY_L) -> atset1:38 */
  [Q_KEY_CODE_LEFT] = 0xe04b, /* qcode:Q_KEY_CODE_LEFT (left) -> linux:105 (KEY_LEFT) -> atset1:57419 */
  [Q_KEY_CODE_LESS] = 0x56, /* qcode:Q_KEY_CODE_LESS (less) -> linux:86 (KEY_102ND) -> atset1:86 */
  [Q_KEY_CODE_LF] = 0x5b, /* qcode:Q_KEY_CODE_LF (lf) -> linux:101 (KEY_LINEFEED) -> atset1:91 */
  [Q_KEY_CODE_M] = 0x32, /* qcode:Q_KEY_CODE_M (m) -> linux:50 (KEY_M) -> atset1:50 */
  [Q_KEY_CODE_MAIL] = 0xe06c, /* qcode:Q_KEY_CODE_MAIL (mail) -> linux:155 (KEY_MAIL) -> atset1:57452 */
  [Q_KEY_CODE_MEDIASELECT] = 0xe06d, /* qcode:Q_KEY_CODE_MEDIASELECT (mediaselect) -> linux:226 (KEY_MEDIA) -> atset1:57453 */
  [Q_KEY_CODE_MENU] = 0xe01e, /* qcode:Q_KEY_CODE_MENU (menu) -> linux:139 (KEY_MENU) -> atset1:57374 */
  [Q_KEY_CODE_META_L] = 0xe05b, /* qcode:Q_KEY_CODE_META_L (meta_l) -> linux:125 (KEY_LEFTMETA) -> atset1:57435 */
  [Q_KEY_CODE_META_R] = 0xe05c, /* qcode:Q_KEY_CODE_META_R (meta_r) -> linux:126 (KEY_RIGHTMETA) -> atset1:57436 */
  [Q_KEY_CODE_MINUS] = 0xc, /* qcode:Q_KEY_CODE_MINUS (minus) -> linux:12 (KEY_MINUS) -> atset1:12 */
  [Q_KEY_CODE_MUHENKAN] = 0x7b, /* qcode:Q_KEY_CODE_MUHENKAN (muhenkan) -> linux:94 (KEY_MUHENKAN) -> atset1:123 */
  [Q_KEY_CODE_N] = 0x31, /* qcode:Q_KEY_CODE_N (n) -> linux:49 (KEY_N) -> atset1:49 */
  [Q_KEY_CODE_NUM_LOCK] = 0x45, /* qcode:Q_KEY_CODE_NUM_LOCK (num_lock) -> linux:69 (KEY_NUMLOCK) -> atset1:69 */
  [Q_KEY_CODE_O] = 0x18, /* qcode:Q_KEY_CODE_O (o) -> linux:24 (KEY_O) -> atset1:24 */
  [Q_KEY_CODE_OPEN] = 0x64, /* qcode:Q_KEY_CODE_OPEN (open) -> linux:134 (KEY_OPEN) -> atset1:100 */
  [Q_KEY_CODE_P] = 0x19, /* qcode:Q_KEY_CODE_P (p) -> linux:25 (KEY_P) -> atset1:25 */
  [Q_KEY_CODE_PASTE] = 0x65, /* qcode:Q_KEY_CODE_PASTE (paste) -> linux:135 (KEY_PASTE) -> atset1:101 */
  [Q_KEY_CODE_PAUSE] = 0xe046, /* qcode:Q_KEY_CODE_PAUSE (pause) -> linux:119 (KEY_PAUSE) -> atset1:57414 */
  [Q_KEY_CODE_PGDN] = 0xe051, /* qcode:Q_KEY_CODE_PGDN (pgdn) -> linux:109 (KEY_PAGEDOWN) -> atset1:57425 */
  [Q_KEY_CODE_PGUP] = 0xe049, /* qcode:Q_KEY_CODE_PGUP (pgup) -> linux:104 (KEY_PAGEUP) -> atset1:57417 */
  [Q_KEY_CODE_POWER] = 0xe05e, /* qcode:Q_KEY_CODE_POWER (power) -> linux:116 (KEY_POWER) -> atset1:57438 */
  [Q_KEY_CODE_PRINT] = 0x54, /* qcode:Q_KEY_CODE_PRINT (sysrq) -> linux:99 (KEY_SYSRQ) -> atset1:84 */
  [Q_KEY_CODE_PROPS] = 0xe006, /* qcode:Q_KEY_CODE_PROPS (props) -> linux:130 (KEY_PROPS) -> atset1:57350 */
  [Q_KEY_CODE_Q] = 0x10, /* qcode:Q_KEY_CODE_Q (q) -> linux:16 (KEY_Q) -> atset1:16 */
  [Q_KEY_CODE_R] = 0x13, /* qcode:Q_KEY_CODE_R (r) -> linux:19 (KEY_R) -> atset1:19 */
  [Q_KEY_CODE_RET] = 0x1c, /* qcode:Q_KEY_CODE_RET (ret) -> linux:28 (KEY_ENTER) -> atset1:28 */
  [Q_KEY_CODE_RIGHT] = 0xe04d, /* qcode:Q_KEY_CODE_RIGHT (right) -> linux:106 (KEY_RIGHT) -> atset1:57421 */
  [Q_KEY_CODE_RO] = 0x73, /* qcode:Q_KEY_CODE_RO (ro) -> linux:89 (KEY_RO) -> atset1:115 */
  [Q_KEY_CODE_S] = 0x1f, /* qcode:Q_KEY_CODE_S (s) -> linux:31 (KEY_S) -> atset1:31 */
  [Q_KEY_CODE_SCROLL_LOCK] = 0x46, /* qcode:Q_KEY_CODE_SCROLL_LOCK (scroll_lock) -> linux:70 (KEY_SCROLLLOCK) -> atset1:70 */
  [Q_KEY_CODE_SEMICOLON] = 0x27, /* qcode:Q_KEY_CODE_SEMICOLON (semicolon) -> linux:39 (KEY_SEMICOLON) -> atset1:39 */
  [Q_KEY_CODE_SHIFT] = 0x2a, /* qcode:Q_KEY_CODE_SHIFT (shift) -> linux:42 (KEY_LEFTSHIFT) -> atset1:42 */
  [Q_KEY_CODE_SHIFT_R] = 0x36, /* qcode:Q_KEY_CODE_SHIFT_R (shift_r) -> linux:54 (KEY_RIGHTSHIFT) -> atset1:54 */
  [Q_KEY_CODE_SLASH] = 0x35, /* qcode:Q_KEY_CODE_SLASH (slash) -> linux:53 (KEY_SLASH) -> atset1:53 */
  [Q_KEY_CODE_SLEEP] = 0xe05f, /* qcode:Q_KEY_CODE_SLEEP (sleep) -> linux:142 (KEY_SLEEP) -> atset1:57439 */
  [Q_KEY_CODE_SPC] = 0x39, /* qcode:Q_KEY_CODE_SPC (spc) -> linux:57 (KEY_SPACE) -> atset1:57 */
  [Q_KEY_CODE_STOP] = 0xe068, /* qcode:Q_KEY_CODE_STOP (stop) -> linux:128 (KEY_STOP) -> atset1:57448 */
  [Q_KEY_CODE_SYSRQ] = 0x54, /* qcode:Q_KEY_CODE_SYSRQ (sysrq) -> linux:99 (KEY_SYSRQ) -> atset1:84 */
  [Q_KEY_CODE_T] = 0x14, /* qcode:Q_KEY_CODE_T (t) -> linux:20 (KEY_T) -> atset1:20 */
  [Q_KEY_CODE_TAB] = 0xf, /* qcode:Q_KEY_CODE_TAB (tab) -> linux:15 (KEY_TAB) -> atset1:15 */
  [Q_KEY_CODE_U] = 0x16, /* qcode:Q_KEY_CODE_U (u) -> linux:22 (KEY_U) -> atset1:22 */
  [Q_KEY_CODE_UNDO] = 0xe007, /* qcode:Q_KEY_CODE_UNDO (undo) -> linux:131 (KEY_UNDO) -> atset1:57351 */
  [Q_KEY_CODE_UP] = 0xe048, /* qcode:Q_KEY_CODE_UP (up) -> linux:103 (KEY_UP) -> atset1:57416 */
  [Q_KEY_CODE_V] = 0x2f, /* qcode:Q_KEY_CODE_V (v) -> linux:47 (KEY_V) -> atset1:47 */
  [Q_KEY_CODE_VOLUMEDOWN] = 0xe02e, /* qcode:Q_KEY_CODE_VOLUMEDOWN (volumedown) -> linux:114 (KEY_VOLUMEDOWN) -> atset1:57390 */
  [Q_KEY_CODE_VOLUMEUP] = 0xe030, /* qcode:Q_KEY_CODE_VOLUMEUP (volumeup) -> linux:115 (KEY_VOLUMEUP) -> atset1:57392 */
  [Q_KEY_CODE_W] = 0x11, /* qcode:Q_KEY_CODE_W (w) -> linux:17 (KEY_W) -> atset1:17 */
  [Q_KEY_CODE_WAKE] = 0xe063, /* qcode:Q_KEY_CODE_WAKE (wake) -> linux:143 (KEY_WAKEUP) -> atset1:57443 */
  [Q_KEY_CODE_X] = 0x2d, /* qcode:Q_KEY_CODE_X (x) -> linux:45 (KEY_X) -> atset1:45 */
  [Q_KEY_CODE_Y] = 0x15, /* qcode:Q_KEY_CODE_Y (y) -> linux:21 (KEY_Y) -> atset1:21 */
  [Q_KEY_CODE_YEN] = 0x7d, /* qcode:Q_KEY_CODE_YEN (yen) -> linux:124 (KEY_YEN) -> atset1:125 */
  [Q_KEY_CODE_Z] = 0x2c, /* qcode:Q_KEY_CODE_Z (z) -> linux:44 (KEY_Z) -> atset1:44 */
};
const uint64_t qemu_input_map_qcode_to_atset1_len = sizeof(qemu_input_map_qcode_to_atset1)/sizeof(qemu_input_map_qcode_to_atset1[0]);

int TranslateScancode(uint8_t scancode, int pressed, uint8_t input[10]) {
	if (scancode >= qemu_input_map_xorgevdev_to_qcode_len) {
		return 0;
	}
	uint16_t qcode = qemu_input_map_xorgevdev_to_qcode[scancode];
	if (qcode >= qemu_input_map_qcode_to_atset1_len) {
		return 0;
	}
  int output_size = 0;
	uint16_t keycode = qemu_input_map_qcode_to_atset1[qcode];
	if (keycode & 0xff00) {
		input[output_size++] = keycode >> 8;
	}
	if (!pressed) {
		keycode |= 0x80;
	}
  if (keycode & 0xff) {
	  input[output_size++] = keycode;
  }
  return output_size;
}
