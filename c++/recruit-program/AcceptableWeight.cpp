


bool TheAcceptableWeight(int weight, char gender)
{
	const	int		MALE_MIN_WEIGHT  = 130;
	const	int		MALE_MAX_WEIGHT  = 250;
	const	int		FMALE_MIN_WEIGHT = 110;
	const	int		FMALE_MAX_WEIGHT = 185;
    bool acceptableWeight;

    acceptableWeight = ((gender == 'm' || gender == 'M') && (weight >= MALE_MIN_WEIGHT && weight <= MALE_MAX_WEIGHT))
    			    || ((gender == 'f' || gender == 'F')&&(weight >= FMALE_MIN_WEIGHT && weight <= FMALE_MAX_WEIGHT));

    return acceptableWeight;
}

