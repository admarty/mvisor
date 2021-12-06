/* 
 * MVisor
 * Copyright (C) 2021 Terrence <terrence@tenclass.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include "keymap.h"

/* This key codes are same as QEMU's */
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

/* The following keymaps are auto-generated by QEMU scripts */

const uint16_t qemu_input_map_usb_to_qcode[252] = {
  [0x4] = Q_KEY_CODE_A, /* usb:4 -> linux:30 (KEY_A) -> qcode:Q_KEY_CODE_A (a) */
  [0x5] = Q_KEY_CODE_B, /* usb:5 -> linux:48 (KEY_B) -> qcode:Q_KEY_CODE_B (b) */
  [0x6] = Q_KEY_CODE_C, /* usb:6 -> linux:46 (KEY_C) -> qcode:Q_KEY_CODE_C (c) */
  [0x7] = Q_KEY_CODE_D, /* usb:7 -> linux:32 (KEY_D) -> qcode:Q_KEY_CODE_D (d) */
  [0x8] = Q_KEY_CODE_E, /* usb:8 -> linux:18 (KEY_E) -> qcode:Q_KEY_CODE_E (e) */
  [0x9] = Q_KEY_CODE_F, /* usb:9 -> linux:33 (KEY_F) -> qcode:Q_KEY_CODE_F (f) */
  [0xa] = Q_KEY_CODE_G, /* usb:10 -> linux:34 (KEY_G) -> qcode:Q_KEY_CODE_G (g) */
  [0xb] = Q_KEY_CODE_H, /* usb:11 -> linux:35 (KEY_H) -> qcode:Q_KEY_CODE_H (h) */
  [0xc] = Q_KEY_CODE_I, /* usb:12 -> linux:23 (KEY_I) -> qcode:Q_KEY_CODE_I (i) */
  [0xd] = Q_KEY_CODE_J, /* usb:13 -> linux:36 (KEY_J) -> qcode:Q_KEY_CODE_J (j) */
  [0xe] = Q_KEY_CODE_K, /* usb:14 -> linux:37 (KEY_K) -> qcode:Q_KEY_CODE_K (k) */
  [0xf] = Q_KEY_CODE_L, /* usb:15 -> linux:38 (KEY_L) -> qcode:Q_KEY_CODE_L (l) */
  [0x10] = Q_KEY_CODE_M, /* usb:16 -> linux:50 (KEY_M) -> qcode:Q_KEY_CODE_M (m) */
  [0x11] = Q_KEY_CODE_N, /* usb:17 -> linux:49 (KEY_N) -> qcode:Q_KEY_CODE_N (n) */
  [0x12] = Q_KEY_CODE_O, /* usb:18 -> linux:24 (KEY_O) -> qcode:Q_KEY_CODE_O (o) */
  [0x13] = Q_KEY_CODE_P, /* usb:19 -> linux:25 (KEY_P) -> qcode:Q_KEY_CODE_P (p) */
  [0x14] = Q_KEY_CODE_Q, /* usb:20 -> linux:16 (KEY_Q) -> qcode:Q_KEY_CODE_Q (q) */
  [0x15] = Q_KEY_CODE_R, /* usb:21 -> linux:19 (KEY_R) -> qcode:Q_KEY_CODE_R (r) */
  [0x16] = Q_KEY_CODE_S, /* usb:22 -> linux:31 (KEY_S) -> qcode:Q_KEY_CODE_S (s) */
  [0x17] = Q_KEY_CODE_T, /* usb:23 -> linux:20 (KEY_T) -> qcode:Q_KEY_CODE_T (t) */
  [0x18] = Q_KEY_CODE_U, /* usb:24 -> linux:22 (KEY_U) -> qcode:Q_KEY_CODE_U (u) */
  [0x19] = Q_KEY_CODE_V, /* usb:25 -> linux:47 (KEY_V) -> qcode:Q_KEY_CODE_V (v) */
  [0x1a] = Q_KEY_CODE_W, /* usb:26 -> linux:17 (KEY_W) -> qcode:Q_KEY_CODE_W (w) */
  [0x1b] = Q_KEY_CODE_X, /* usb:27 -> linux:45 (KEY_X) -> qcode:Q_KEY_CODE_X (x) */
  [0x1c] = Q_KEY_CODE_Y, /* usb:28 -> linux:21 (KEY_Y) -> qcode:Q_KEY_CODE_Y (y) */
  [0x1d] = Q_KEY_CODE_Z, /* usb:29 -> linux:44 (KEY_Z) -> qcode:Q_KEY_CODE_Z (z) */
  [0x1e] = Q_KEY_CODE_1, /* usb:30 -> linux:2 (KEY_1) -> qcode:Q_KEY_CODE_1 (1) */
  [0x1f] = Q_KEY_CODE_2, /* usb:31 -> linux:3 (KEY_2) -> qcode:Q_KEY_CODE_2 (2) */
  [0x20] = Q_KEY_CODE_3, /* usb:32 -> linux:4 (KEY_3) -> qcode:Q_KEY_CODE_3 (3) */
  [0x21] = Q_KEY_CODE_4, /* usb:33 -> linux:5 (KEY_4) -> qcode:Q_KEY_CODE_4 (4) */
  [0x22] = Q_KEY_CODE_5, /* usb:34 -> linux:6 (KEY_5) -> qcode:Q_KEY_CODE_5 (5) */
  [0x23] = Q_KEY_CODE_6, /* usb:35 -> linux:7 (KEY_6) -> qcode:Q_KEY_CODE_6 (6) */
  [0x24] = Q_KEY_CODE_7, /* usb:36 -> linux:8 (KEY_7) -> qcode:Q_KEY_CODE_7 (7) */
  [0x25] = Q_KEY_CODE_8, /* usb:37 -> linux:9 (KEY_8) -> qcode:Q_KEY_CODE_8 (8) */
  [0x26] = Q_KEY_CODE_9, /* usb:38 -> linux:10 (KEY_9) -> qcode:Q_KEY_CODE_9 (9) */
  [0x27] = Q_KEY_CODE_0, /* usb:39 -> linux:11 (KEY_0) -> qcode:Q_KEY_CODE_0 (0) */
  [0x28] = Q_KEY_CODE_RET, /* usb:40 -> linux:28 (KEY_ENTER) -> qcode:Q_KEY_CODE_RET (ret) */
  [0x29] = Q_KEY_CODE_ESC, /* usb:41 -> linux:1 (KEY_ESC) -> qcode:Q_KEY_CODE_ESC (esc) */
  [0x2a] = Q_KEY_CODE_BACKSPACE, /* usb:42 -> linux:14 (KEY_BACKSPACE) -> qcode:Q_KEY_CODE_BACKSPACE (backspace) */
  [0x2b] = Q_KEY_CODE_TAB, /* usb:43 -> linux:15 (KEY_TAB) -> qcode:Q_KEY_CODE_TAB (tab) */
  [0x2c] = Q_KEY_CODE_SPC, /* usb:44 -> linux:57 (KEY_SPACE) -> qcode:Q_KEY_CODE_SPC (spc) */
  [0x2d] = Q_KEY_CODE_MINUS, /* usb:45 -> linux:12 (KEY_MINUS) -> qcode:Q_KEY_CODE_MINUS (minus) */
  [0x2e] = Q_KEY_CODE_EQUAL, /* usb:46 -> linux:13 (KEY_EQUAL) -> qcode:Q_KEY_CODE_EQUAL (equal) */
  [0x2f] = Q_KEY_CODE_BRACKET_LEFT, /* usb:47 -> linux:26 (KEY_LEFTBRACE) -> qcode:Q_KEY_CODE_BRACKET_LEFT (bracket_left) */
  [0x30] = Q_KEY_CODE_BRACKET_RIGHT, /* usb:48 -> linux:27 (KEY_RIGHTBRACE) -> qcode:Q_KEY_CODE_BRACKET_RIGHT (bracket_right) */
  [0x31] = Q_KEY_CODE_BACKSLASH, /* usb:49 -> linux:43 (KEY_BACKSLASH) -> qcode:Q_KEY_CODE_BACKSLASH (backslash) */
  [0x32] = Q_KEY_CODE_BACKSLASH, /* usb:50 -> linux:43 (KEY_BACKSLASH) -> qcode:Q_KEY_CODE_BACKSLASH (backslash) */
  [0x33] = Q_KEY_CODE_SEMICOLON, /* usb:51 -> linux:39 (KEY_SEMICOLON) -> qcode:Q_KEY_CODE_SEMICOLON (semicolon) */
  [0x34] = Q_KEY_CODE_APOSTROPHE, /* usb:52 -> linux:40 (KEY_APOSTROPHE) -> qcode:Q_KEY_CODE_APOSTROPHE (apostrophe) */
  [0x35] = Q_KEY_CODE_GRAVE_ACCENT, /* usb:53 -> linux:41 (KEY_GRAVE) -> qcode:Q_KEY_CODE_GRAVE_ACCENT (grave_accent) */
  [0x36] = Q_KEY_CODE_COMMA, /* usb:54 -> linux:51 (KEY_COMMA) -> qcode:Q_KEY_CODE_COMMA (comma) */
  [0x37] = Q_KEY_CODE_DOT, /* usb:55 -> linux:52 (KEY_DOT) -> qcode:Q_KEY_CODE_DOT (dot) */
  [0x38] = Q_KEY_CODE_SLASH, /* usb:56 -> linux:53 (KEY_SLASH) -> qcode:Q_KEY_CODE_SLASH (slash) */
  [0x39] = Q_KEY_CODE_CAPS_LOCK, /* usb:57 -> linux:58 (KEY_CAPSLOCK) -> qcode:Q_KEY_CODE_CAPS_LOCK (caps_lock) */
  [0x3a] = Q_KEY_CODE_F1, /* usb:58 -> linux:59 (KEY_F1) -> qcode:Q_KEY_CODE_F1 (f1) */
  [0x3b] = Q_KEY_CODE_F2, /* usb:59 -> linux:60 (KEY_F2) -> qcode:Q_KEY_CODE_F2 (f2) */
  [0x3c] = Q_KEY_CODE_F3, /* usb:60 -> linux:61 (KEY_F3) -> qcode:Q_KEY_CODE_F3 (f3) */
  [0x3d] = Q_KEY_CODE_F4, /* usb:61 -> linux:62 (KEY_F4) -> qcode:Q_KEY_CODE_F4 (f4) */
  [0x3e] = Q_KEY_CODE_F5, /* usb:62 -> linux:63 (KEY_F5) -> qcode:Q_KEY_CODE_F5 (f5) */
  [0x3f] = Q_KEY_CODE_F6, /* usb:63 -> linux:64 (KEY_F6) -> qcode:Q_KEY_CODE_F6 (f6) */
  [0x40] = Q_KEY_CODE_F7, /* usb:64 -> linux:65 (KEY_F7) -> qcode:Q_KEY_CODE_F7 (f7) */
  [0x41] = Q_KEY_CODE_F8, /* usb:65 -> linux:66 (KEY_F8) -> qcode:Q_KEY_CODE_F8 (f8) */
  [0x42] = Q_KEY_CODE_F9, /* usb:66 -> linux:67 (KEY_F9) -> qcode:Q_KEY_CODE_F9 (f9) */
  [0x43] = Q_KEY_CODE_F10, /* usb:67 -> linux:68 (KEY_F10) -> qcode:Q_KEY_CODE_F10 (f10) */
  [0x44] = Q_KEY_CODE_F11, /* usb:68 -> linux:87 (KEY_F11) -> qcode:Q_KEY_CODE_F11 (f11) */
  [0x45] = Q_KEY_CODE_F12, /* usb:69 -> linux:88 (KEY_F12) -> qcode:Q_KEY_CODE_F12 (f12) */
  [0x46] = Q_KEY_CODE_SYSRQ, /* usb:70 -> linux:99 (KEY_SYSRQ) -> qcode:Q_KEY_CODE_SYSRQ (sysrq) */
  [0x47] = Q_KEY_CODE_SCROLL_LOCK, /* usb:71 -> linux:70 (KEY_SCROLLLOCK) -> qcode:Q_KEY_CODE_SCROLL_LOCK (scroll_lock) */
  [0x48] = Q_KEY_CODE_PAUSE, /* usb:72 -> linux:119 (KEY_PAUSE) -> qcode:Q_KEY_CODE_PAUSE (pause) */
  [0x49] = Q_KEY_CODE_INSERT, /* usb:73 -> linux:110 (KEY_INSERT) -> qcode:Q_KEY_CODE_INSERT (insert) */
  [0x4a] = Q_KEY_CODE_HOME, /* usb:74 -> linux:102 (KEY_HOME) -> qcode:Q_KEY_CODE_HOME (home) */
  [0x4b] = Q_KEY_CODE_PGUP, /* usb:75 -> linux:104 (KEY_PAGEUP) -> qcode:Q_KEY_CODE_PGUP (pgup) */
  [0x4c] = Q_KEY_CODE_DELETE, /* usb:76 -> linux:111 (KEY_DELETE) -> qcode:Q_KEY_CODE_DELETE (delete) */
  [0x4d] = Q_KEY_CODE_END, /* usb:77 -> linux:107 (KEY_END) -> qcode:Q_KEY_CODE_END (end) */
  [0x4e] = Q_KEY_CODE_PGDN, /* usb:78 -> linux:109 (KEY_PAGEDOWN) -> qcode:Q_KEY_CODE_PGDN (pgdn) */
  [0x4f] = Q_KEY_CODE_RIGHT, /* usb:79 -> linux:106 (KEY_RIGHT) -> qcode:Q_KEY_CODE_RIGHT (right) */
  [0x50] = Q_KEY_CODE_LEFT, /* usb:80 -> linux:105 (KEY_LEFT) -> qcode:Q_KEY_CODE_LEFT (left) */
  [0x51] = Q_KEY_CODE_DOWN, /* usb:81 -> linux:108 (KEY_DOWN) -> qcode:Q_KEY_CODE_DOWN (down) */
  [0x52] = Q_KEY_CODE_UP, /* usb:82 -> linux:103 (KEY_UP) -> qcode:Q_KEY_CODE_UP (up) */
  [0x53] = Q_KEY_CODE_NUM_LOCK, /* usb:83 -> linux:69 (KEY_NUMLOCK) -> qcode:Q_KEY_CODE_NUM_LOCK (num_lock) */
  [0x54] = Q_KEY_CODE_KP_DIVIDE, /* usb:84 -> linux:98 (KEY_KPSLASH) -> qcode:Q_KEY_CODE_KP_DIVIDE (kp_divide) */
  [0x55] = Q_KEY_CODE_KP_MULTIPLY, /* usb:85 -> linux:55 (KEY_KPASTERISK) -> qcode:Q_KEY_CODE_KP_MULTIPLY (kp_multiply) */
  [0x56] = Q_KEY_CODE_KP_SUBTRACT, /* usb:86 -> linux:74 (KEY_KPMINUS) -> qcode:Q_KEY_CODE_KP_SUBTRACT (kp_subtract) */
  [0x57] = Q_KEY_CODE_KP_ADD, /* usb:87 -> linux:78 (KEY_KPPLUS) -> qcode:Q_KEY_CODE_KP_ADD (kp_add) */
  [0x58] = Q_KEY_CODE_KP_ENTER, /* usb:88 -> linux:96 (KEY_KPENTER) -> qcode:Q_KEY_CODE_KP_ENTER (kp_enter) */
  [0x59] = Q_KEY_CODE_KP_1, /* usb:89 -> linux:79 (KEY_KP1) -> qcode:Q_KEY_CODE_KP_1 (kp_1) */
  [0x5a] = Q_KEY_CODE_KP_2, /* usb:90 -> linux:80 (KEY_KP2) -> qcode:Q_KEY_CODE_KP_2 (kp_2) */
  [0x5b] = Q_KEY_CODE_KP_3, /* usb:91 -> linux:81 (KEY_KP3) -> qcode:Q_KEY_CODE_KP_3 (kp_3) */
  [0x5c] = Q_KEY_CODE_KP_4, /* usb:92 -> linux:75 (KEY_KP4) -> qcode:Q_KEY_CODE_KP_4 (kp_4) */
  [0x5d] = Q_KEY_CODE_KP_5, /* usb:93 -> linux:76 (KEY_KP5) -> qcode:Q_KEY_CODE_KP_5 (kp_5) */
  [0x5e] = Q_KEY_CODE_KP_6, /* usb:94 -> linux:77 (KEY_KP6) -> qcode:Q_KEY_CODE_KP_6 (kp_6) */
  [0x5f] = Q_KEY_CODE_KP_7, /* usb:95 -> linux:71 (KEY_KP7) -> qcode:Q_KEY_CODE_KP_7 (kp_7) */
  [0x60] = Q_KEY_CODE_KP_8, /* usb:96 -> linux:72 (KEY_KP8) -> qcode:Q_KEY_CODE_KP_8 (kp_8) */
  [0x61] = Q_KEY_CODE_KP_9, /* usb:97 -> linux:73 (KEY_KP9) -> qcode:Q_KEY_CODE_KP_9 (kp_9) */
  [0x62] = Q_KEY_CODE_KP_0, /* usb:98 -> linux:82 (KEY_KP0) -> qcode:Q_KEY_CODE_KP_0 (kp_0) */
  [0x63] = Q_KEY_CODE_KP_DECIMAL, /* usb:99 -> linux:83 (KEY_KPDOT) -> qcode:Q_KEY_CODE_KP_DECIMAL (kp_decimal) */
  [0x64] = Q_KEY_CODE_LESS, /* usb:100 -> linux:86 (KEY_102ND) -> qcode:Q_KEY_CODE_LESS (less) */
  [0x65] = Q_KEY_CODE_COMPOSE, /* usb:101 -> linux:127 (KEY_COMPOSE) -> qcode:Q_KEY_CODE_COMPOSE (compose) */
  [0x66] = Q_KEY_CODE_POWER, /* usb:102 -> linux:116 (KEY_POWER) -> qcode:Q_KEY_CODE_POWER (power) */
  [0x67] = Q_KEY_CODE_KP_EQUALS, /* usb:103 -> linux:117 (KEY_KPEQUAL) -> qcode:Q_KEY_CODE_KP_EQUALS (kp_equals) */
  [0x68] = Q_KEY_CODE_UNMAPPED, /* usb:104 -> linux:183 (KEY_F13) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x69] = Q_KEY_CODE_UNMAPPED, /* usb:105 -> linux:184 (KEY_F14) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6a] = Q_KEY_CODE_UNMAPPED, /* usb:106 -> linux:185 (KEY_F15) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6b] = Q_KEY_CODE_UNMAPPED, /* usb:107 -> linux:186 (KEY_F16) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6c] = Q_KEY_CODE_UNMAPPED, /* usb:108 -> linux:187 (KEY_F17) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6d] = Q_KEY_CODE_UNMAPPED, /* usb:109 -> linux:188 (KEY_F18) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6e] = Q_KEY_CODE_UNMAPPED, /* usb:110 -> linux:189 (KEY_F19) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x6f] = Q_KEY_CODE_UNMAPPED, /* usb:111 -> linux:190 (KEY_F20) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x70] = Q_KEY_CODE_UNMAPPED, /* usb:112 -> linux:191 (KEY_F21) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x71] = Q_KEY_CODE_UNMAPPED, /* usb:113 -> linux:192 (KEY_F22) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x72] = Q_KEY_CODE_UNMAPPED, /* usb:114 -> linux:193 (KEY_F23) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x73] = Q_KEY_CODE_UNMAPPED, /* usb:115 -> linux:194 (KEY_F24) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x74] = Q_KEY_CODE_OPEN, /* usb:116 -> linux:134 (KEY_OPEN) -> qcode:Q_KEY_CODE_OPEN (open) */
  [0x75] = Q_KEY_CODE_HELP, /* usb:117 -> linux:138 (KEY_HELP) -> qcode:Q_KEY_CODE_HELP (help) */
  [0x76] = Q_KEY_CODE_MENU, /* usb:118 -> linux:139 (KEY_MENU) -> qcode:Q_KEY_CODE_MENU (menu) */
  [0x77] = Q_KEY_CODE_FRONT, /* usb:119 -> linux:132 (KEY_FRONT) -> qcode:Q_KEY_CODE_FRONT (front) */
  [0x78] = Q_KEY_CODE_STOP, /* usb:120 -> linux:128 (KEY_STOP) -> qcode:Q_KEY_CODE_STOP (stop) */
  [0x79] = Q_KEY_CODE_AGAIN, /* usb:121 -> linux:129 (KEY_AGAIN) -> qcode:Q_KEY_CODE_AGAIN (again) */
  [0x7a] = Q_KEY_CODE_UNDO, /* usb:122 -> linux:131 (KEY_UNDO) -> qcode:Q_KEY_CODE_UNDO (undo) */
  [0x7b] = Q_KEY_CODE_CUT, /* usb:123 -> linux:137 (KEY_CUT) -> qcode:Q_KEY_CODE_CUT (cut) */
  [0x7c] = Q_KEY_CODE_COPY, /* usb:124 -> linux:133 (KEY_COPY) -> qcode:Q_KEY_CODE_COPY (copy) */
  [0x7d] = Q_KEY_CODE_PASTE, /* usb:125 -> linux:135 (KEY_PASTE) -> qcode:Q_KEY_CODE_PASTE (paste) */
  [0x7e] = Q_KEY_CODE_FIND, /* usb:126 -> linux:136 (KEY_FIND) -> qcode:Q_KEY_CODE_FIND (find) */
  [0x7f] = Q_KEY_CODE_AUDIOMUTE, /* usb:127 -> linux:113 (KEY_MUTE) -> qcode:Q_KEY_CODE_AUDIOMUTE (audiomute) */
  [0x80] = Q_KEY_CODE_VOLUMEUP, /* usb:128 -> linux:115 (KEY_VOLUMEUP) -> qcode:Q_KEY_CODE_VOLUMEUP (volumeup) */
  [0x81] = Q_KEY_CODE_VOLUMEDOWN, /* usb:129 -> linux:114 (KEY_VOLUMEDOWN) -> qcode:Q_KEY_CODE_VOLUMEDOWN (volumedown) */
  [0x85] = Q_KEY_CODE_KP_COMMA, /* usb:133 -> linux:121 (KEY_KPCOMMA) -> qcode:Q_KEY_CODE_KP_COMMA (kp_comma) */
  [0x87] = Q_KEY_CODE_RO, /* usb:135 -> linux:89 (KEY_RO) -> qcode:Q_KEY_CODE_RO (ro) */
  [0x88] = Q_KEY_CODE_KATAKANAHIRAGANA, /* usb:136 -> linux:93 (KEY_KATAKANAHIRAGANA) -> qcode:Q_KEY_CODE_KATAKANAHIRAGANA (katakanahiragana) */
  [0x89] = Q_KEY_CODE_YEN, /* usb:137 -> linux:124 (KEY_YEN) -> qcode:Q_KEY_CODE_YEN (yen) */
  [0x8a] = Q_KEY_CODE_HENKAN, /* usb:138 -> linux:92 (KEY_HENKAN) -> qcode:Q_KEY_CODE_HENKAN (henkan) */
  [0x8b] = Q_KEY_CODE_MUHENKAN, /* usb:139 -> linux:94 (KEY_MUHENKAN) -> qcode:Q_KEY_CODE_MUHENKAN (muhenkan) */
  [0x8c] = Q_KEY_CODE_UNMAPPED, /* usb:140 -> linux:95 (KEY_KPJPCOMMA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x90] = Q_KEY_CODE_UNMAPPED, /* usb:144 -> linux:122 (KEY_HANGEUL) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x91] = Q_KEY_CODE_UNMAPPED, /* usb:145 -> linux:123 (KEY_HANJA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x92] = Q_KEY_CODE_UNMAPPED, /* usb:146 -> linux:90 (KEY_KATAKANA) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0x93] = Q_KEY_CODE_HIRAGANA, /* usb:147 -> linux:91 (KEY_HIRAGANA) -> qcode:Q_KEY_CODE_HIRAGANA (hiragana) */
  [0x94] = Q_KEY_CODE_UNMAPPED, /* usb:148 -> linux:85 (KEY_ZENKAKUHANKAKU) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb6] = Q_KEY_CODE_UNMAPPED, /* usb:182 -> linux:179 (KEY_KPLEFTPAREN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xb7] = Q_KEY_CODE_UNMAPPED, /* usb:183 -> linux:180 (KEY_KPRIGHTPAREN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xe0] = Q_KEY_CODE_CTRL, /* usb:224 -> linux:29 (KEY_LEFTCTRL) -> qcode:Q_KEY_CODE_CTRL (ctrl) */
  [0xe1] = Q_KEY_CODE_SHIFT, /* usb:225 -> linux:42 (KEY_LEFTSHIFT) -> qcode:Q_KEY_CODE_SHIFT (shift) */
  [0xe2] = Q_KEY_CODE_ALT, /* usb:226 -> linux:56 (KEY_LEFTALT) -> qcode:Q_KEY_CODE_ALT (alt) */
  [0xe3] = Q_KEY_CODE_META_L, /* usb:227 -> linux:125 (KEY_LEFTMETA) -> qcode:Q_KEY_CODE_META_L (meta_l) */
  [0xe4] = Q_KEY_CODE_CTRL_R, /* usb:228 -> linux:97 (KEY_RIGHTCTRL) -> qcode:Q_KEY_CODE_CTRL_R (ctrl_r) */
  [0xe5] = Q_KEY_CODE_SHIFT_R, /* usb:229 -> linux:54 (KEY_RIGHTSHIFT) -> qcode:Q_KEY_CODE_SHIFT_R (shift_r) */
  [0xe6] = Q_KEY_CODE_ALT_R, /* usb:230 -> linux:100 (KEY_RIGHTALT) -> qcode:Q_KEY_CODE_ALT_R (alt_r) */
  [0xe7] = Q_KEY_CODE_META_R, /* usb:231 -> linux:126 (KEY_RIGHTMETA) -> qcode:Q_KEY_CODE_META_R (meta_r) */
  [0xe8] = Q_KEY_CODE_AUDIOPLAY, /* usb:232 -> linux:164 (KEY_PLAYPAUSE) -> qcode:Q_KEY_CODE_AUDIOPLAY (audioplay) */
  [0xe9] = Q_KEY_CODE_AUDIOSTOP, /* usb:233 -> linux:166 (KEY_STOPCD) -> qcode:Q_KEY_CODE_AUDIOSTOP (audiostop) */
  [0xea] = Q_KEY_CODE_AUDIOPREV, /* usb:234 -> linux:165 (KEY_PREVIOUSSONG) -> qcode:Q_KEY_CODE_AUDIOPREV (audioprev) */
  [0xeb] = Q_KEY_CODE_AUDIONEXT, /* usb:235 -> linux:163 (KEY_NEXTSONG) -> qcode:Q_KEY_CODE_AUDIONEXT (audionext) */
  [0xec] = Q_KEY_CODE_UNMAPPED, /* usb:236 -> linux:161 (KEY_EJECTCD) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xed] = Q_KEY_CODE_VOLUMEUP, /* usb:237 -> linux:115 (KEY_VOLUMEUP) -> qcode:Q_KEY_CODE_VOLUMEUP (volumeup) */
  [0xee] = Q_KEY_CODE_VOLUMEDOWN, /* usb:238 -> linux:114 (KEY_VOLUMEDOWN) -> qcode:Q_KEY_CODE_VOLUMEDOWN (volumedown) */
  [0xef] = Q_KEY_CODE_AUDIOMUTE, /* usb:239 -> linux:113 (KEY_MUTE) -> qcode:Q_KEY_CODE_AUDIOMUTE (audiomute) */
  [0xf0] = Q_KEY_CODE_UNMAPPED, /* usb:240 -> linux:150 (KEY_WWW) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf1] = Q_KEY_CODE_AC_BACK, /* usb:241 -> linux:158 (KEY_BACK) -> qcode:Q_KEY_CODE_AC_BACK (ac_back) */
  [0xf2] = Q_KEY_CODE_AC_FORWARD, /* usb:242 -> linux:159 (KEY_FORWARD) -> qcode:Q_KEY_CODE_AC_FORWARD (ac_forward) */
  [0xf3] = Q_KEY_CODE_STOP, /* usb:243 -> linux:128 (KEY_STOP) -> qcode:Q_KEY_CODE_STOP (stop) */
  [0xf4] = Q_KEY_CODE_FIND, /* usb:244 -> linux:136 (KEY_FIND) -> qcode:Q_KEY_CODE_FIND (find) */
  [0xf5] = Q_KEY_CODE_UNMAPPED, /* usb:245 -> linux:177 (KEY_SCROLLUP) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf6] = Q_KEY_CODE_UNMAPPED, /* usb:246 -> linux:178 (KEY_SCROLLDOWN) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf7] = Q_KEY_CODE_UNMAPPED, /* usb:247 -> linux:176 (KEY_EDIT) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xf8] = Q_KEY_CODE_SLEEP, /* usb:248 -> linux:142 (KEY_SLEEP) -> qcode:Q_KEY_CODE_SLEEP (sleep) */
  [0xf9] = Q_KEY_CODE_UNMAPPED, /* usb:249 -> linux:152 (KEY_SCREENLOCK) -> qcode:Q_KEY_CODE_UNMAPPED (unnamed) */
  [0xfa] = Q_KEY_CODE_AC_REFRESH, /* usb:250 -> linux:173 (KEY_REFRESH) -> qcode:Q_KEY_CODE_AC_REFRESH (ac_refresh) */
  [0xfb] = Q_KEY_CODE_CALCULATOR, /* usb:251 -> linux:140 (KEY_CALC) -> qcode:Q_KEY_CODE_CALCULATOR (calculator) */
};
const size_t qemu_input_map_usb_to_qcode_len = sizeof(qemu_input_map_usb_to_qcode)/sizeof(qemu_input_map_usb_to_qcode[0]);

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

const size_t qemu_input_map_qcode_to_atset1_len = sizeof(qemu_input_map_qcode_to_atset1)/sizeof(qemu_input_map_qcode_to_atset1[0]);

/* This function first translate the current user input to QEMU keycode,
 * then translate to the PS2 scancode.
 * The output `transcoded` might have more than one byte.
 */
int TranslateScancode(uint8_t scancode, int pressed, uint8_t transcoded[10]) {
	if (scancode >= qemu_input_map_usb_to_qcode_len) {
		return 0;
	}
	uint16_t qcode = qemu_input_map_usb_to_qcode[scancode];
	if (qcode >= qemu_input_map_qcode_to_atset1_len) {
		return 0;
	}
  int transcoded_size = 0;
	uint16_t keycode = qemu_input_map_qcode_to_atset1[qcode];
	if (keycode & 0xff00) {
		transcoded[transcoded_size++] = keycode >> 8;
	}
	if (!pressed) {
		keycode |= 0x80;
	}
  if (keycode & 0xff) {
	  transcoded[transcoded_size++] = keycode;
  }
  return transcoded_size;
}
