/* user and group to drop privileges to */
static const char *user  = "root";
static const char *group = "root";

/* colors */
static const float textcolors[NUMCOLS][3] = {
    [INIT]   = {1.0, 1.0, 1.0},
    [INPUT]  = {0.3, 0.5, 1.0},
    [FAILED] = {1.0, 0.0, 0.0}, 
};


/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

static const char *textfamily = "JetBrains Mono";
static const int textsize = 70;


/* Background image path, should be available to the user above */
static const char* background_image = "/home/ivanika/Pictures/wallpapers/10.jpg";