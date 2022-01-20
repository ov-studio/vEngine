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
// $hash=14eaca76dba704ee64f454aaca821a6818012fc6$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_OVERLAY_CONTROLLER_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_OVERLAY_CONTROLLER_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_view_t;
struct _cef_window_t;

///
// Controller for an overlay that contains a contents View added via
// cef_window_t::AddOverlayView. Methods exposed by this controller should be
// called in preference to functions of the same name exposed by the contents
// View unless otherwise indicated. Methods must be called on the browser
// process UI thread unless otherwise indicated.
///
typedef struct _cef_overlay_controller_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns true (1) if this object is valid.
  ///
  int(CEF_CALLBACK* is_valid)(struct _cef_overlay_controller_t* self);

  ///
  // Returns true (1) if this object is the same as |that| object.
  ///
  int(CEF_CALLBACK* is_same)(struct _cef_overlay_controller_t* self,
                             struct _cef_overlay_controller_t* that);

  ///
  // Returns the contents View for this overlay.
  ///
  struct _cef_view_t*(CEF_CALLBACK* get_contents_view)(
      struct _cef_overlay_controller_t* self);

  ///
  // Returns the top-level Window hosting this overlay. Use this function
  // instead of calling get_window() on the contents View.
  ///
  struct _cef_window_t*(CEF_CALLBACK* get_window)(
      struct _cef_overlay_controller_t* self);

  ///
  // Returns the docking mode for this overlay.
  ///
  cef_docking_mode_t(CEF_CALLBACK* get_docking_mode)(
      struct _cef_overlay_controller_t* self);

  ///
  // Destroy this overlay.
  ///
  void(CEF_CALLBACK* destroy)(struct _cef_overlay_controller_t* self);

  ///
  // Sets the bounds (size and position) of this overlay. This will set the
  // bounds of the contents View to match and trigger a re-layout if necessary.
  // |bounds| is in parent coordinates and any insets configured on this overlay
  // will be ignored. Use this function only for overlays created with a docking
  // mode value of CEF_DOCKING_MODE_CUSTOM. With other docking modes modify the
  // insets of this overlay and/or layout of the contents View and call
  // size_to_preferred_size() instead to calculate the new size and re-position
  // the overlay if necessary.
  ///
  void(CEF_CALLBACK* set_bounds)(struct _cef_overlay_controller_t* self,
                                 const cef_rect_t* bounds);

  ///
  // Returns the bounds (size and position) of this overlay in parent
  // coordinates.
  ///
  cef_rect_t(CEF_CALLBACK* get_bounds)(struct _cef_overlay_controller_t* self);

  ///
  // Returns the bounds (size and position) of this overlay in DIP screen
  // coordinates.
  ///
  cef_rect_t(CEF_CALLBACK* get_bounds_in_screen)(
      struct _cef_overlay_controller_t* self);

  ///
  // Sets the size of this overlay without changing the position. This will set
  // the size of the contents View to match and trigger a re-layout if
  // necessary. |size| is in parent coordinates and any insets configured on
  // this overlay will be ignored. Use this function only for overlays created
  // with a docking mode value of CEF_DOCKING_MODE_CUSTOM. With other docking
  // modes modify the insets of this overlay and/or layout of the contents View
  // and call size_to_preferred_size() instead to calculate the new size and re-
  // position the overlay if necessary.
  ///
  void(CEF_CALLBACK* set_size)(struct _cef_overlay_controller_t* self,
                               const cef_size_t* size);

  ///
  // Returns the size of this overlay in parent coordinates.
  ///
  cef_size_t(CEF_CALLBACK* get_size)(struct _cef_overlay_controller_t* self);

  ///
  // Sets the position of this overlay without changing the size. |position| is
  // in parent coordinates and any insets configured on this overlay will be
  // ignored. Use this function only for overlays created with a docking mode
  // value of CEF_DOCKING_MODE_CUSTOM. With other docking modes modify the
  // insets of this overlay and/or layout of the contents View and call
  // size_to_preferred_size() instead to calculate the new size and re-position
  // the overlay if necessary.
  ///
  void(CEF_CALLBACK* set_position)(struct _cef_overlay_controller_t* self,
                                   const cef_point_t* position);

  ///
  // Returns the position of this overlay in parent coordinates.
  ///
  cef_point_t(CEF_CALLBACK* get_position)(
      struct _cef_overlay_controller_t* self);

  ///
  // Sets the insets for this overlay. |insets| is in parent coordinates. Use
  // this function only for overlays created with a docking mode value other
  // than CEF_DOCKING_MODE_CUSTOM.
  ///
  void(CEF_CALLBACK* set_insets)(struct _cef_overlay_controller_t* self,
                                 const cef_insets_t* insets);

  ///
  // Returns the insets for this overlay in parent coordinates.
  ///
  cef_insets_t(CEF_CALLBACK* get_insets)(
      struct _cef_overlay_controller_t* self);

  ///
  // Size this overlay to its preferred size and trigger a re-layout if
  // necessary. The position of overlays created with a docking mode value of
  // CEF_DOCKING_MODE_CUSTOM will not be modified by calling this function. With
  // other docking modes this function may re-position the overlay if necessary
  // to accommodate the new size and any insets configured on the contents View.
  ///
  void(CEF_CALLBACK* size_to_preferred_size)(
      struct _cef_overlay_controller_t* self);

  ///
  // Sets whether this overlay is visible. Overlays are hidden by default. If
  // this overlay is hidden then it and any child Views will not be drawn and,
  // if any of those Views currently have focus, then focus will also be
  // cleared. Painting is scheduled as needed.
  ///
  void(CEF_CALLBACK* set_visible)(struct _cef_overlay_controller_t* self,
                                  int visible);

  ///
  // Returns whether this overlay is visible. A View may be visible but still
  // not drawn in a Window if any parent Views are hidden. Call is_drawn() to
  // determine whether this overlay and all parent Views are visible and will be
  // drawn.
  ///
  int(CEF_CALLBACK* is_visible)(struct _cef_overlay_controller_t* self);

  ///
  // Returns whether this overlay is visible and drawn in a Window. A View is
  // drawn if it and all parent Views are visible. To determine if the
  // containing Window is visible to the user on-screen call is_visible() on the
  // Window.
  ///
  int(CEF_CALLBACK* is_drawn)(struct _cef_overlay_controller_t* self);
} cef_overlay_controller_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_OVERLAY_CONTROLLER_CAPI_H_
