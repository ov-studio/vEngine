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
// $hash=fcfe34c1517ebdb3f00c1f737b91361e771b820d$
//

#ifndef CEF_INCLUDE_CAPI_CEF_EXTENSION_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_EXTENSION_CAPI_H_
#pragma once

#include "capi/cef_base_capi.h"
#include "capi/cef_values_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_extension_handler_t;
struct _cef_request_context_t;

///
// Object representing an extension. Methods may be called on any thread unless
// otherwise indicated.
///
typedef struct _cef_extension_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns the unique extension identifier. This is calculated based on the
  // extension public key, if available, or on the extension path. See
  // https://developer.chrome.com/extensions/manifest/key for details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_identifier)(
      struct _cef_extension_t* self);

  ///
  // Returns the absolute path to the extension directory on disk. This value
  // will be prefixed with PK_DIR_RESOURCES if a relative path was passed to
  // cef_request_context_t::LoadExtension.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_path)(struct _cef_extension_t* self);

  ///
  // Returns the extension manifest contents as a cef_dictionary_value_t object.
  // See https://developer.chrome.com/extensions/manifest for details.
  ///
  struct _cef_dictionary_value_t*(CEF_CALLBACK* get_manifest)(
      struct _cef_extension_t* self);

  ///
  // Returns true (1) if this object is the same extension as |that| object.
  // Extensions are considered the same if identifier, path and loader context
  // match.
  ///
  int(CEF_CALLBACK* is_same)(struct _cef_extension_t* self,
                             struct _cef_extension_t* that);

  ///
  // Returns the handler for this extension. Will return NULL for internal
  // extensions or if no handler was passed to
  // cef_request_context_t::LoadExtension.
  ///
  struct _cef_extension_handler_t*(CEF_CALLBACK* get_handler)(
      struct _cef_extension_t* self);

  ///
  // Returns the request context that loaded this extension. Will return NULL
  // for internal extensions or if the extension has been unloaded. See the
  // cef_request_context_t::LoadExtension documentation for more information
  // about loader contexts. Must be called on the browser process UI thread.
  ///
  struct _cef_request_context_t*(CEF_CALLBACK* get_loader_context)(
      struct _cef_extension_t* self);

  ///
  // Returns true (1) if this extension is currently loaded. Must be called on
  // the browser process UI thread.
  ///
  int(CEF_CALLBACK* is_loaded)(struct _cef_extension_t* self);

  ///
  // Unload this extension if it is not an internal extension and is currently
  // loaded. Will result in a call to
  // cef_extension_handler_t::OnExtensionUnloaded on success.
  ///
  void(CEF_CALLBACK* unload)(struct _cef_extension_t* self);
} cef_extension_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_EXTENSION_CAPI_H_
