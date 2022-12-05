if((Wind(time))/Load(time) > Max_Renewables_Penetration){
    Pump = το περισευμα αιολικης
}

if((Wind(time))/Load(time) <= Max_Renewables_Penetration){
    το pump διοχετευει (παραγει) ενεργεια στο δικτυο ιση με P=Ppump
}


Εγώ έγραψα αυτό αλλά ειναι λάθος


if((Wind(time))/Load(time)>Max_Renewables_Penetration){
    Wind(time) = (1 - Max_Renewables_Penetration) * Load(time);
    Ppump = Wind(time);
}

Pthermal(time) = Load(time) - Solar(time) - Wind(time);

if((Wind(time))/Load(time) <= Max_Renewables_Penetration){
    Wind(time) = Max_Renewables_Penetration * Load(time);
    Ppump = 5000MW;
}

Pthermal(time) = Load(time) - Solar(time) - Wind(time);
