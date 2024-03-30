


bool TheAcceptableHeight(int height, char gender)
{
	const	int		MALE_MIN_HEIGHT  = 65;
	const	int		MALE_MAX_HEIGHT  = 80;
	const	int		FMALE_MIN_HEIGHT = 62;
	const	int		FMALE_MAX_HEIGHT = 75;
    bool    acceptableHeight;


    acceptableHeight = ((gender == 'm' || gender == 'M') && (height >= MALE_MIN_HEIGHT && height <= MALE_MAX_HEIGHT))
    		         ||((gender == 'f' || gender == 'F')&&(height >= FMALE_MIN_HEIGHT && height <= FMALE_MAX_HEIGHT));

    return acceptableHeight;
}//put in the separate file

