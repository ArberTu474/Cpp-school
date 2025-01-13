// Consider a class Movie that contains information about a movie. The class
// has the following attributes:
// ■ The movie name
// ■ The MPAA rating (for example, G, PG, PG-13, R)
// ■ The number of people that have rated this movie as a 1 (Terrible)
// ■ The number of people that have rated this movie as a 2 (Bad)
// ■ The number of people that have rated this movie as a 3 (OK)
// ■ The number of people that have rated this movie as a 4 (Good)
// ■ The number of people that have rated this movie as a 5 (Great)

// Implement the class with accessor and mutator functions for the movie
// name and MPAA rating.

// Write a function addRating that takes an integer
// as an input parameter. The function should verify that the parameter is
// a number between 1 and 5, and if so, increment the number of people
// rating the movie that match the input parameter. For example, if 3 is
// the input parameter, then the number of people that rated the movie as
// a 3 should be incremented by 1.

// Write another function, getAverage,
// that returns the average value for all of the movie ratings.

// Finally, add
// a constructor that allows the programmer to create the object with a
// specified name and MPAA rating. The number of people rating the movie
// should be set to 0 in the constructor.

// Test the class by writing a main function that creates at least two movie
// objects, adds at least five ratings for each movie, and outputs the movie
// name, MPAA rating, and average rating for each movie object.

#include <iostream>
#include <string>

class Movie
{
private:
  std::string name;
  std::string mpaa_rating;
  // int rating_1;
  // int rating_2;
  // int rating_3;
  // int rating_4;
  // int rating_5;

  int rating[5];

public:
  Movie(std::string name, std::string mpaa_rating)
  {
    this->name = name;
    this->mpaa_rating = mpaa_rating;
    for (int i = 0; i < 5; i++)
    {
      rating[i] = 0;
    }
  }

  void set_mpaa_rating(std::string rating)
  {
    mpaa_rating = rating;
  }

  std::string get_mpaa_rating()
  {
    return mpaa_rating;
  }

  void set_name(std::string name)
  {
    this->name = name;
  }

  std::string get_name()
  {
    return name;
  }

  void add_rating(int rating)
  {
    if (rating >= 1 && rating <= 5)
    {
      this->rating[rating - 1]++;
    }
  }

  double get_average()
  {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
      sum += (rating[i] * (i + 1));
      count += rating[i];
    }

    return (double)sum / count;
  }

  void print_info()
  {
    std::cout << "Name: " << name << "\n";
    std::cout << "MPAA rating: " << mpaa_rating << "\n";

    std::cout << "\n"
              << "Ratings" << "\n";

    for (int i = 0; i < 5; i++)
    {
      std::cout << i + 1 << ". ";
      for (int j = 0; j < rating[i]; j++)
      {
        std::cout << "* ";
      }
      std::cout << "\n";
    }

    // std::cout << "\n"
    //           << "Average rating: " << get_average() << "\n";
    std::printf("Average rating: %.1f\n", get_average());
  }
};

int main()
{
  Movie movie_1("Pokemon", "PG");
  movie_1.add_rating(1);
  movie_1.add_rating(1);
  movie_1.add_rating(2);
  movie_1.add_rating(2);
  movie_1.add_rating(2);
  movie_1.add_rating(3);
  movie_1.add_rating(5);
  movie_1.add_rating(5);
  movie_1.add_rating(5);
  movie_1.add_rating(5);
  movie_1.add_rating(5);

  movie_1.print_info();

  return 0;
}