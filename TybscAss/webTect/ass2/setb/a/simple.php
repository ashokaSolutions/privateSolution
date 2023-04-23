<html>
    <body>
        <?php   
            $xml=simplexml_load_file("books.xml");
            foreach($xml->book as $book){
                echo "<hr>";
                echo $book->bookno."<br>";
                echo $book->bookname."<br>";
                echo $book->authorname."<br>";
                echo $book->price."<br>";
                echo $book->year."<br>";
            }
        ?>    
    </body>
</html>
