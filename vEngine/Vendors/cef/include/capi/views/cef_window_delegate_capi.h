// Copyright (c) 2022 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=cd5d7c4e83237ceb39c5639489ca6004d2d69f0c$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
#pragma once

#include "capi/views/cef_panel_delegate_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_window_t;

///
// Implement this structure to handle window events. The functions of this
// structure will be called on the browser process UI thread unless otherwise
// indicated.
///
typedef struct _cef_window_delegate_t {
  ///
  // Base structure.
  ///
  cef_panel_delegate_t base;

  ///
  // Called when |window| is created.
  ///
  void(CEF_CALLBACK* on_window_created)(struct _cef_window_delegate_t* self,
                                        struct _cef_window_t* window);

  ///
  // Called when |window| is destroyed. Release all references to |window| and
  // do not attempt to execute any functions on |window| after this callback
  // returns.
  ///
  void(CEF_CALLBACK* on_window_destroyed)(struct _cef_window_delegate_t* self,
                                          struct _cef_window_t* window);

  ///
  // Return the parent for |window| or NULL if the |window| does not have a
  // parent. Windows with parents will not get a taskbar button. Set |is_menu|
  // to true (1) if |window| will be displayed as a menu, in which case it will
  // not be clipped to the parent window bounds. Set |can_activate_menu| to
  // false (0) if |is_menu| is true (1) and |window| should not be activated
  // (given keyboard focus) when displayed.
  ///
  struct _cef_window_t*(CEF_CALLBACK* get_parent_window)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window,
      int* is_menu,
      int* can_activate_menu);

  ///
  // Return the initial bounds for |window| in density independent pixel (DIP)
  // coordinates. If this function returns an NULL CefRect then
  // get_preferred_size() will be called to retrieve the size, and the window
  // will be placed on the screen with origin (0,0). This function can be used
  // in combination with cef_view_t::get_bounds_in_screen() to restore the
  // previous window bounds.
  ///
  cef_rect_t(CEF_CALLBACK* get_initial_bounds)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window);

  ///
  // Return the initial show state for |window|.
  ///
  cef_show_state_t(CEF_CALLBACK* get_initial_show_state)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window);

  ///
  // Return true (1) if |window| should be created without a frame or title bar.
  // The window will be resizable if can_resize() returns true (1). Use
  // cef_window_t::set_draggable_regions() to specify draggable regions.
  ///
  int(CEF_CALLBACK* is_frameless)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  // Return true (1) if |window| can be resized.
  ///
  int(CEF_CALLBACK* can_resize)(struct _cef_window_delegate_t* self,
                                struct _cef_window_t* window);

  ///
  // Return true (1) if |window| can be maximized.
  ///
  int(CEF_CALLBACK* can_maximize)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  // Return true (1) if |window| can be minimized.
  ///
  int(CEF_CALLBACK* can_minimize)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  // Return true (1) if |window| can be closed. This will be called for user-
  // initiated window close actions and when cef_window_t::close() is called.
  ///
  int(CEF_CALLBACK* can_close)(struct _cef_window_delegate_t* self,
                               struct _cef_window_t* window);

  ///
  // Called when a keyboard accelerator registered with
  // cef_window_t::SetAccelerator is triggered. Return true (1) if the
  // accelerator was handled or false (0) otherwise.
  ///
  int(CEF_CALLBACK* on_accelerator)(struct _cef_window_delegate_t* self,
                                    struct _cef_window_t* window,
                                    int command_id);

  ///
  // Called after all other controls in the window have had a chance to handle
  // the event. |event| contains information about the keyboard event. Return
  // true (1) if the keyboard event was handled or false (0) otherwise.
  ///
  int(CEF_CALLBACK* on_key_event)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window,
                                  const struct _cef_key_event_t* event);
} cef_window_delegate_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
