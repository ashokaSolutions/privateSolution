package com.sumedhTYBSC.project.sumedhTyProject;

import org.springframework.data.relational.core.sql.In;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.server.ResponseStatusException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.*;

@RestController
public class PhotoController {
//YOU CANNOT ADD LIST OUTSIDE PSVMM SO USE "LIST.OF"
    //private List<Photo> db=List.of(new Photo("1","text.jpg"),new Photo("2","hello.png"));

//    private Map<String,Photo> db=new HashMap<>(){
//        {
//            put("1",new Photo("1","fuvk.jpg"));
//        }
//        {
//            put("2",new Photo("2","ok.png"));
//        }
//    };

    PhotoService photoService=new PhotoService();

    PhotoController(PhotoService photoService){
        this.photoService=photoService;
    }
    @GetMapping("/")
    public String hello(){
        return "hello there aarti";
    }

    //all pics
    @GetMapping("/photo")
    public Collection<Photo> get(){
        return photoService.gets();
    }

    //one specific file
    @GetMapping("/photo/{id}")
    public Photo get(@PathVariable String id){
        Photo pic=photoService.get(id);
        if(pic==null) {
            //this will thow not found exception and code will stop there and will not reach return
            throw new ResponseStatusException(HttpStatus.NOT_FOUND);
        }
        return pic;
    }

    @GetMapping("/test")
    ResponseEntity<String> hello1() {
        return new ResponseEntity<>( HttpStatus.NOT_FOUND);
    }

    @PostMapping("/photo")
    Photo save(@RequestPart("data")MultipartFile file) throws IOException {
        Photo photo=new Photo();
        photo.setId(UUID.randomUUID().toString());
        photo.setData(file.getBytes());
        photo.setFileName(photo.getFileName());
        photoService.put(photo.getId(),photo);
        return photo;
    }
}
/*
    Getmapping gets the page entered*/