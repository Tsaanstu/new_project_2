#ifndef NEW_PROJECT_2_ALLOMANTIC_POWER_HPP
#define NEW_PROJECT_2_ALLOMANTIC_POWER_HPP

class Allomantic_power {
 public:
    Allomantic_power(short int force = 0, short int distant_force = 0,
                     double accuracy_of_shooting = 0, short int distance_of_walk = 0);
    Allomantic_power(const Allomantic_power &ap) = default;
    ~Allomantic_power() = default;
    Allomantic_power &operator=(const Allomantic_power &ap2);

    //  get
    short int get_force() const;
    short int get_distant_force() const;
    double get_accuracy_of_shooting() const;
    short int get_distance_of_walk() const;

    //  set
    void set_force(short int force);
    void set_distant_force(short int distant_force);
    void set_accuracy_of_shooting(double accuracy_of_shooting);
    void set_distance_of_walk(short int distance_of_walk);
 private:
    short int force_;
    short int distant_force_;
    double accuracy_of_shooting_;
    short int distance_of_walk_;
};

#endif //NEW_PROJECT_2_ALLOMANTIC_POWER_HPP
