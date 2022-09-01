class bookmyshowservice {
    vector<cinemahall> cinemas;
    public:
    vector<Movie> getMovies(Date date, string city);
    vector<cinemahall> getcinemahalls(string city);
}

class cinemahall{
    int cinemahallID;
    string cinemahallname;
    Address address;
    vector<audi>audilist;
    public:
    map<Date, Movie> getMovies(vector<Date> datelist);
    map<Date, Show> getShows(vector<Date> datelist);
}

class Address{
    int pincode;
    string street;
    string city;
    string state;
    string country;

}

class audi{
    int audiID;
    string audiname;
    int totalseats;
    vector<Show> shows;
}

class Show{
    int showID;
    Movie movie;
    Date starttime;
    Date endtime;
    cinemahall cinemaPlayedAt;
    vector<Seat> seats;

}

class Seat {

	int seatId;
	SeatType seatType;
	SeatStatus seatStatus;
	double price;

}

enum SeatType {

	DELUX, VIP, ECONOMY, OTHER;

}

enum SeatStatus {

	BOOKED, AVAILABLE, RESERVED, NOT_AVAILABLE;

}

class Movie {

	string movieName;
	int movieId;
	int durationInMins;
	string language;
	Genre genre;
	Date releaseDate;
	Map<string, vector<Show>> cityShowMap;

}

enum Genre {

	SCI_FI, DRAMA, ROM_COM, FANTASY;
}

class User {

	int userId;
	Search searchObj;

}

class SystemMember extends User {

	Account account;
	string name;
	string email;
	Address address;

}



class Member extends SystemMember {

	 Booking makeBooking(Booking booking);
	 vector<Booking> getBooking();

}

class Admin extends SystemMember {

	 boolean addMovie(Movie movie);
	 boolean addShow(Show show);

}

class Account {

	string userName;
	string password;

}

class Search {

	 vector<Movie> searchMoviesByNames(string name);
	 vector<Movie> searchMoviesByGenre(Genre genre);
	 vector<Movie> searchMoviesByLanguage(string language);
	 vector<Movie> searchMoviesByDate(Date releaseDate);
}

class Booking {

	string bookingId;
	Date bookingDate;
	Member member;
	Audi audi;
	Show show;
	BookingStatus bookingStatus;
	double totalAmount;
	vector<Seat> seats;
	Payment paymentObj;

	 boolean makePayment(Payment payment);

}

 class Payment {

	double amount;
	Date paymentDate;
	int transactionId;
	PaymentStatus paymentStatus;

}

 enum BookingStatus {

	REQUESTED, PENDING, CONFIRMED, CANCELLED;
}

 enum PaymentStatus {

	UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED;

}