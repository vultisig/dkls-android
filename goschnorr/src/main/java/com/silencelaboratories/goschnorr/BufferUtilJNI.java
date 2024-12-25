// THIS FILE IS GENERATED MANUALLY , PLEASE DON'T REMOVE IT
package com.silencelaboratories.goschnorr;
public class BufferUtilJNI {
    public final static native void set_bytes_on_tss_buffer(tss_buffer jarg1, byte[] jarg1_);

    public final static native byte[] get_bytes_from_tss_buffer(tss_buffer jarg1);

    public final static native void set_bytes_on_go_slice(go_slice jarg1, byte[] jarg1_);

    public final static native byte[] get_bytes_from_go_slice(go_slice jarg1);
}