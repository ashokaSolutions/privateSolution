package com.sumedhTYBSC.project.sumedhTyProject;

import javax.validation.constraints.NotEmpty;
import java.lang.annotation.Native;

public class Photo {
    private String id;

    @NotEmpty
    private byte[] data;

    public Photo() {

    }

    public byte[] getData() {
        return data;
    }

    public void setData(byte[] data) {
        this.data = data;
    }

    private String fileName;

    public Photo(String id, String fileName) {
        this.id = id;
        this.fileName = fileName;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }
}
