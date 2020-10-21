class Main {

    public static void main(String[] args) {
        Publication publication = new Publication("The new era");
        System.out.println(publication.getInfo());

        Newspaper newspaper = new Newspaper("Football results", "Sport news");
        System.out.println(newspaper.getInfo());

        Article article = new Article("Why the Sun is hot", "Dr James Smith");
        System.out.println(article.getInfo());

        Announcement announcement = new Announcement("Will sell a house", 30);
        System.out.println(announcement.getInfo());
    }

}

class Publication {

    private String title;

    public Publication(String title) {
        this.title = title;
    }

    public final String getInfo() {
        return getType() + getDetails() + ": " + this.title;
    }

    public String getType() {
        return "Publication";
    }

    public String getDetails() {
        return "";
    }

}

class Newspaper extends Publication {

    private String source;

    public Newspaper(String title, String source) {
        super(title);
        this.source = source;
    }

    public String getType() {
        return "Newspaper";
    }

    public String getDetails() {
        return " (source - " + this.source + ")";
    }

}

class Article extends Publication {

    private String author;

    public Article(String title, String author) {
        super(title);
        this.author = author;
    }

    public String getType() {
        return "Article";
    }

    public String getDetails() {
        return " (author - " + this.author + ")";
    }

}

class Announcement extends Publication {

    private int daysToExpire;

    public Announcement(String title, int daysToExpire) {
        super(title);
        this.daysToExpire = daysToExpire;
    }

    public String getType() {
        return "Announcement";
    }

    public String getDetails() {
        return " (days to expire - " + this.daysToExpire + ")";
    }

}
