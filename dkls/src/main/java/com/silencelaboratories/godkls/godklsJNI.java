/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.3.0
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.silencelaboratories.godkls;

public class godklsJNI {
  public final static native int LIB_ABORT_PROTOCOL_AND_BAN_PARTY_1_get();
  public final static native int LIB_ABORT_PROTOCOL_PARTY_1_get();
  public final static native void tss_buffer_ptr_set(long jarg1, tss_buffer jarg1_, long jarg2);
  public final static native long tss_buffer_ptr_get(long jarg1, tss_buffer jarg1_);
  public final static native void tss_buffer_len_set(long jarg1, tss_buffer jarg1_, long jarg2);
  public final static native long tss_buffer_len_get(long jarg1, tss_buffer jarg1_);
  public final static native long new_tss_buffer();
  public final static native void delete_tss_buffer(long jarg1);
  public final static native void go_slice_ptr_set(long jarg1, go_slice jarg1_, long jarg2);
  public final static native long go_slice_ptr_get(long jarg1, go_slice jarg1_);
  public final static native void go_slice_len_set(long jarg1, go_slice jarg1_, long jarg2);
  public final static native long go_slice_len_get(long jarg1, go_slice jarg1_);
  public final static native void go_slice_cap_set(long jarg1, go_slice jarg1_, long jarg2);
  public final static native long go_slice_cap_get(long jarg1, go_slice jarg1_);
  public final static native long new_go_slice();
  public final static native void delete_go_slice(long jarg1);
  public final static native void Handle__0_set(long jarg1, Handle jarg1_, int jarg2);
  public final static native int Handle__0_get(long jarg1, Handle jarg1_);
  public final static native long new_Handle();
  public final static native void delete_Handle(long jarg1);
  public final static native void tss_buffer_free(long jarg1, tss_buffer jarg1_);
  public final static native int dkls_keygen_setupmsg_new(long jarg1, long jarg2, go_slice jarg2_, long jarg3, go_slice jarg3_, long jarg4, tss_buffer jarg4_);
  public final static native int dkls_keygen_session_from_setup(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, Handle jarg3_);
  public final static native int dkls_key_refresh_session_from_setup(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, Handle jarg3_, long jarg4, Handle jarg4_);
  public final static native int dkls_keygen_session_input_message(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3);
  public final static native int dkls_keygen_session_output_message(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_keygen_session_message_receiver(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, long jarg4, tss_buffer jarg4_);
  public final static native int dkls_keygen_session_finish(long jarg1, Handle jarg1_, long jarg2, Handle jarg2_);
  public final static native int dkls_keygen_session_free(long jarg1, Handle jarg1_);
  public final static native int dkls_presign_from_bytes(long jarg1, go_slice jarg1_, long jarg2, Handle jarg2_);
  public final static native int dkls_presign_to_bytes(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_presign_session_id(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_key_export_receiver_new(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, tss_buffer jarg3_, long jarg4, Handle jarg4_);
  public final static native int dkls_key_export_receiver_input_message(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3);
  public final static native int dkls_key_export_receiver_finish(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_key_exporter(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, go_slice jarg3_, long jarg4, tss_buffer jarg4_, long jarg5, tss_buffer jarg5_);
  public final static native int dkls_key_import_initiator_new(long jarg1, go_slice jarg1_, short jarg2, long jarg3, go_slice jarg3_, long jarg4, tss_buffer jarg4_, long jarg5, Handle jarg5_);
  public final static native int dkls_key_importer_new(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, Handle jarg3_);
  public final static native int dkls_keyshare_from_bytes(long jarg1, go_slice jarg1_, long jarg2, Handle jarg2_);
  public final static native int dkls_keyshare_to_bytes(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_keyshare_public_key(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_keyshare_key_id(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_keyshare_derive_child_public_key(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_, long jarg3, tss_buffer jarg3_);
  public final static native int dkls_keyshare_to_refresh_bytes(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_refresh_share_from_bytes(long jarg1, tss_buffer jarg1_, long jarg2, Handle jarg2_);
  public final static native int dkls_refresh_share_to_bytes(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_keyshare_free(long jarg1, Handle jarg1_);
  public final static native int dkls_keyshare_chaincode(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_qc_setupmsg_new(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, go_slice jarg3_, long jarg4, long jarg5, go_slice jarg5_, long jarg6, tss_buffer jarg6_);
  public final static native int dkls_qc_session_from_setup(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, Handle jarg3_, long jarg4, Handle jarg4_);
  public final static native int dkls_qc_session_input_message(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3);
  public final static native int dkls_qc_session_output_message(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_qc_session_message_receiver(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, long jarg4, tss_buffer jarg4_);
  public final static native int dkls_qc_session_finish(long jarg1, Handle jarg1_, long jarg2, Handle jarg2_);
  public final static native int dkls_qc_session_free(long jarg1, Handle jarg1_);
  public final static native int dkls_decode_key_id(long jarg1, go_slice jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_decode_session_id(long jarg1, go_slice jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_decode_message(long jarg1, go_slice jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_decode_party_name(long jarg1, go_slice jarg1_, long jarg2, long jarg3, tss_buffer jarg3_);
  public final static native int dkls_sign_setupmsg_new(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, go_slice jarg3_, long jarg4, go_slice jarg4_, long jarg5, tss_buffer jarg5_);
  public final static native int dkls_finish_setupmsg_new(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, go_slice jarg3_, long jarg4, tss_buffer jarg4_);
  public final static native int dkls_sign_session_from_setup(long jarg1, go_slice jarg1_, long jarg2, go_slice jarg2_, long jarg3, Handle jarg3_, long jarg4, Handle jarg4_);
  public final static native int dkls_sign_session_input_message(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, int[] jarg3);
  public final static native int dkls_sign_session_output_message(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_sign_session_message_receiver(long jarg1, Handle jarg1_, long jarg2, go_slice jarg2_, long jarg3, long jarg4, tss_buffer jarg4_);
  public final static native int dkls_sign_session_finish(long jarg1, Handle jarg1_, long jarg2, tss_buffer jarg2_);
  public final static native int dkls_sign_session_free(long jarg1, Handle jarg1_);
}