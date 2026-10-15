#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 700

#include "libft.h"
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

/* ==================== COLOURS AND KAOMOJIS ==================== */

#define MINT "\033[38;2;69;215;170m"
#define ROSE "\033[38;2;229;138;138m"
#define GOLD "\033[38;2;255;198;109m"
#define DIM  "\033[38;2;140;160;170m"
#define RESET "\033[0m"
#define COUNT(array) (sizeof(array) / sizeof((array)[0]))

static const char *success_kaomojis[] = {
    "(ง •̀_•́)ง",
    "ᕦ(ò_óˇ)ᕤ",
    "(☞ﾟヮﾟ)☞",
    "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧",
    "(⌐■_■)",
    "٩(◕‿◕｡)۶",
    "ヽ(•‿•)ノ",
    "(๑˃ᴗ˂)ﻭ",
    "＼(＾▽＾)／",
    "(｡•̀ᴗ-)✧",
    "(￣▽￣)ノ",
    "(≧▽≦)",
    "ヾ(⌐■_■)ノ♪",
    "( •̀ ω •́ )✧",
    "ᕕ( ᐛ )ᕗ",
    "(ﾉ´ヮ`)ﾉ*: ･ﾟ",
    "٩(ˊᗜˋ*)و",
    "(๑•̀ㅂ•́)و✧",
    "(￣ー￣)ｂ",
    "(☞ ͡° ͜ʖ ͡°)☞",
    "(づ｡◕‿‿◕｡)づ",
    "ヽ(´▽`)/",
    "( •̀ᴗ•́ )و",
    "(✿◠‿◠)",
    "♪ヽ(･ˇ∀ˇ･ゞ)",
    "(ﾉﾟ0ﾟ)ﾉ~",
    "＼(￣▽￣)／",
    "(｡◕‿◕｡)",
    "(｀・ω・´)ゞ",
    "ヾ(≧▽≦*)o",
    "(๑>ᴗ<๑)",
    "(≧◡≦) ♡",
    "(｡♥‿♥｡)",
    "(ﾉ´ヮ´)ﾉ*:･ﾟ✧",
    "(≧∇≦)/",
    "٩(｡•́‿•̀｡)۶",
    "(๑>◡<๑)",
    "(๑˃̵ᴗ˂̵)و",
    "( ˶ˆᗜˆ˵ )",
    "(˶ᵔ ᵕ ᵔ˶)",
    "(๑•ᴗ•๑)♡",
    "(✧ω✧)",
    "(☆▽☆)",
    "(✯◡✯)",
    "(⌒▽⌒)☆",
    "(つ≧▽≦)つ",
    "(つ✧ω✧)つ",
    "(ﾉ^ヮ^)ﾉ*:・ﾟ✧",
    "(っ˘ω˘ς )",
    "(≧ω≦)",
    "(ﾉ◕ヮ◕)ﾉ",
    "(o^▽^o)",
    "(o´∀`o)",
    "( ´ ω ` )",
    "( ´ ▽ ` )ﾉ",
    "(=^･ω･^=)",
    "ฅ^•ﻌ•^ฅ",
    "ʕ•ᴥ•ʔ",
    "ʕっ•ᴥ•ʔっ",
    "(づ￣ ³￣)づ",
    "(っ´▽`)っ",
    "(ﾉ´ з `)ノ",
    "(｡･ω･｡)ﾉ♡",
    "(￣▽￣)ゞ",
    "(๑˘ᵕ˘)",
    "(˘▽˘)っ",
    "( ˙꒳˙ )",
    "(ﾉ≧∀≦)ﾉ",
    "(ﾉﾟ▽ﾟ)ﾉ",
    "ヽ(>∀<☆)ノ",
    "(ﾉ´∀｀*)ﾉ",
    "(っ•ᴗ•)っ",
    "(˶˃ ᵕ ˂˶)",
    "(๑•̀ᗝ•́)૭",
    "( •̀ .̫ •́ )✧",
    "(｡•̀ᴗ•́｡)",
    "(◕‿◕✿)",
    "(◠‿◠✿)",
    "( ˘ ³˘)♥",
    "(✿´‿`)",
    "(๑ˊ͈ ꇴ ˋ͈)♡",
    "(つ≧▽≦)つ♡",
    "(ง ˙˘˙ )ว",
    "♪(๑ᴖ◡ᴖ๑)♪",
    "(ノ^∇^)",
    "٩(ˊᗜˋ*)و ♡",
    "(✿˵•́ᴗ•̀˵)",
    "(っ˘ڡ˘ς)",
    "(๑´ڡ`๑)",
    "(≧∇≦)b",
    "(๑•̀ㅂ•́)و",
    "( •̀ᄇ• ́)ﻭ✧",
    "(⌒‿⌒)",
    "(๑˃ᴗ˂)ﻭ♡",
    "(≧▽≦)ゞ",
    "(ﾉ◕ヮ◕)ﾉ♡",
    "(っ＾▿＾)۶",
    "(づ｡◕‿‿◕｡)づ♡",
    "(✿◕‿◕)",
    "(｡◕‿◕｡)♡",
    "(๑˘︶˘๑)",
    "(っ˘ω˘ς)♡",
    "(๑•̀ω•́)و",
    "(ﾉ´ヮ`)ﾉ*:･ﾟ✧",
    "(ﾉ´∀｀)ﾉ",
    "(◍•ᴗ•◍)♡",
    "(｡•̀ᴗ-)✧♡",
    "(｡･∀･)ﾉﾞ",
    "(๑╹ω╹๑)",
    "(｡･ω･｡)",
    "(≧∇≦)ﾉ",
    "(๑˃̵ᴗ˂̵)و♡",
    "(づ￣ ³￣)づ♡",
    "(´｡• ᵕ •｡`) ♡",
    "(๑˃̵ᴗ˂̵)و ✧",
    "(✧∀✧)",
    "(｡•̀ᴗ•́)و",
    "( ˘͈ ᵕ ˘͈♡)",
    "(ﾉ≧ڡ≦)ﾉ",
    "(っ´ω`)ﾉ",
    "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧♡",
    "(｡･ω･｡)ﾉ♡♡",
    "(๑•̀ㅁ•́๑)✧",
    "(*≧ω≦*)",
    "(♡°▽°♡)",
    "(〃＾▽＾〃)",
    "(*ฅ́˘ฅ̀*)",
    "(≧◡≦)ゞ",
    "(ﾉ>ω<)ﾉ",
    "(づ ◕‿◕ )づ",
    "(♡˙︶˙♡)",
    "(*´꒳`*)",
    "(✿˵•́ ᴗ •̀˵)",
    "( ๑ ˃̵ᴗ˂̵)و",
    "(っ•́｡•́)♪",
    "(๑˘ᴗ˘๑)",
    "(ﾉ^ヮ^)ﾉ",
    "(｡◕‿◕｡)ﾉ",
    "(๑˃̶͈̀◡˂̶͈́๑)",
    "(≧ω≦)b",
    "(ﾉ´ヮ`)ﾉ♡",
    "(˶ᵔ ᵕ ᵔ˶)♡",
    "(๑•̀ᄇ•́)و",
    "(✿◕‿◕✿)",
    "(つ♡ω♡)つ",
    "(ღ˘⌣˘ღ)",
    "(ง •̀▿•́)ง",
    "(ﾉ◕ヮ◕)ﾉ*:✧",
    "(ﾉ≧▽≦)ﾉ",
    "٩(๑❛ᴗ❛๑)۶",
    "( ˶•̀ᗜ•́˶ )",
    "( ˶˃⤙˂˶ )",
    "(｡•ᴗ•｡)♡",
    "(୨୧ ❛ᴗ❛)✧",
    "(๑•̀ᗜ•́)૭",
    "( ੭ ˙ᗜ˙ )੭",
    "ᕙ(  •̀ ᗜ •́  )ᕗ",
    "(ฅ´ω`ฅ)",
    "(ฅ^ω^ฅ)",
    "(=^‥^=)",
    "(=ↀωↀ=)",
    "(ΦωΦ)",
    "(=｀ω´=)",
    "ฅ(＾・ω・＾ฅ)",
    "(=^･ｪ･^=)",
    "(U・x・U)",
    "U^ｪ^U",
    "(ᵔᴥᵔ)",
    "ʕ•́ᴥ•̀ʔっ",
    "ʕง•ᴥ•ʔง",
    "ʕ·ᴥ·ʔ",
    "ʕᵔᴥᵔʔ",
    "(｡•̀ᴗ•́)و✧",
    "(ง ͠° ͟ل͜ ͡°)ง",
    "(ง ᵕᴗᵕ)ว",
    "(ง ื▿ ื)ว",
    "(ง ˙ω˙)ว",
    "٩(๑˃̵ᴗ˂̵)و",
    "٩(๑•̀o•́๑)و",
    "٩(◦`꒳´◦)۶",
    "٩(｡•ω•｡)و",
    "ヽ(•̀ω•́ )ゝ",
    "ヽ(✿ﾟ▽ﾟ)ノ",
    "ヽ(´ー｀)ノ",
    "ヽ(｡◕o◕｡)ﾉ",
    "＼(≧▽≦)／",
    "＼(●~▽~●)／",
    "＼(o￣∇￣o)／",
    "ヾ(＠⌒ー⌒＠)ノ",
    "ヾ(•ω•`)o",
    "ヾ(≧∇≦*)ゝ",
    "ヾ(´▽｀;)ゝ",
    "(づ ◕‿◕ )づ✧",
    "(つ´∀｀)つ",
    "(づ｡◕‿◕｡)づ✦",
    "(っ⌒‿⌒)っ",
    "(っ´∀｀)っ",
    "(つ˘◡˘)づ",
    "(づ˶•༝•˶)づ♡",
    "(๑˃̶͈̀◡˂̶͈́๑)",
    "(๑˘︶˘๑)✿",
    "(๑╹◡╹๑)",
    "(๑´ω`๑)",
    "(๑•̀⌄•́)و",
    "(๑•̀﹏•́)و✧",
    "(๑¯◡¯๑)",
    "(๑´•.̫ • `๑)",
    "(๑´•᎑•`๑)",
    "(๑ᵔ⤙ᵔ๑)",
    "(๑˃̵ᴗ˂̵)ﻭ",
    "(♡´౪`♡)",
    "(♡ω♡)",
    "(◍•ᴗ•◍)✧",
    "(◕ᴗ◕✿)",
    "(◕‿◕)♡",
    "(◠‿◠)♡",
    "(◡‿◡✿)",
    "(◕‿◕)✧",
    "(｡•̀ᴗ-)و",
    "(｡◕‿◕｡)✧",
    "(｡･ω･｡)✿",
    "(｡･∀･｡)",
    "(*・ω・)ﾉ",
    "(*´ω｀*)",
    "(*ﾟ▽ﾟ*)",
    "(*ˊᗜˋ*)",
    "( ˘ω˘ )",
    "( ˊᵕˋ )♡",
    "( ˶ᵔᵕᵔ˶ )",
    "( ˶ˆ꒳ˆ˵ )",
    "( ˶˘ ³˘˵ )",
    "( ˶ᵕ ᵕ˶ )",
    "( ˵ •̀ ᴗ •́ ˵ )",
    "( •̀ᴗ•́ )✧",
    "( •̀ω•́ )و✧",
    "( •̀ᵕ•́ )و",
    "(≧∀≦)ゞ",
    "(≧∇≦)ﾉ✧",
    "(≧◡≦)✧",
    "(≧ω≦)ゞ",
    "(✧◡✧)",
    "(☆ω☆)",
    "(☆∀☆)",
    "(✯ω✯)",
    "(★ω★)",
    "(✿╹◡╹)",
    "(✿´꒳`)",
    "(✿◠▽◠)",
    "(✿◕ᗜ◕)",
    "(ﾉﾟヮﾟ)ﾉ",
    "(ﾉ≧ω≦)ﾉ",
    "(ﾉ´ω`)ﾉ✧",
    "(ﾉ˶>ᗜ<˵)ﾉ",
    "(ﾉ◕ヮ◕)ﾉ✦",
    "(ﾉ◕ヮ◕)ﾉ☆",
    "(ﾉ≧∀≦)ﾉ☆",
    "ᕕ(⌐■_■)ᕗ",
    "ᕕ( ᐕ )ᕗ",
    "ᕦ(๑•̀ᴗ•́๑)ᕤ",
    "ᕦ(•̀o•́)ᕤ",
    "☞(⌐■_■)☞",
    "(☞ﾟ∀ﾟ)☞",
    "(⌐▨_▨)",
    "(￣▽￣)b",
    "(￣ω￣)ゞ",
    "(￣ー￣)ゞ",
    "(￣▽￣)✧",
    "(￣∇￣)ﾉ",
    "(￣▽￣)ノ☆",
    "(￣∀￣)ゞ",
    "(｀･ω･´)ゞ",
    "(｀・∀・´)",
    "(｀▽´)ゞ",
    "(｀ω´)ゞ",
    "(๑˃̵ᴗ˂̵)و☆",
    "(๑•ᴗ•๑)✧",
    "(๑•ω•๑)♡",
    "(๑•̀ㅁ•́)و✧",
    "(๑´ڡ`๑)♡",
    "(ﾉ´ヮ`)ﾉ☆",
    "(ﾉ´ヮ`)ﾉ✦",
    "(ﾉ´ヮ`)ﾉ♫",
    "(っ˘▽˘)っ",
    "(っ◕‿◕)っ",
    "٩(ˊᗜˋ)و☆",
    "٩(๑•̀ㅂ•́)و☆",
    "(づ￣▽￣)づ",
    "(๑•̀ㅂ•́)ﻭ☆",
    "(っ´▽`)っ☆"
};

static const char *failure_kaomojis[] = {
    "(╯°□°)╯︵ ┻━┻",
    "(ಠ_ಠ)",
    "(눈_눈)",
    "(ノಠ益ಠ)ノ",
    "(；￣Д￣)",
    "(ಥ_ಥ)",
    "(¬_¬)",
    "(＃`Д´)",
    "(╥﹏╥)",
    "(ง'̀-'́)ง",
    "(ノ｀Д´)ノ彡┻━┻",
    "(╬ಠ益ಠ)",
    "(；一_一)",
    "(｡•́︿•̀｡)",
    "(´；ω；`)",
    "(￣ヘ￣)",
    "(≖_≖ )",
    "(っ- ‸ - ς)",
    "(ᗒᗣᗕ)՞",
    "(；´д｀)ゞ",
    "(´-﹏-`；)",
    "(つ﹏⊂)",
    "(ノ_<。)",
    "(╯ರ ~ ರ)╯︵ ┻━┻",
    "(ಠ益ಠ)",
    "(¬､¬)",
    "(；¬д¬)",
    "(╬ Ò﹏Ó)",
    "(ಥ﹏ಥ)",
    "(っ˘̩╭╮˘̩)っ",
    "(｡•́︿•̀｡)♡",
    "(つ﹏<。)",
    "(ಥ⌣ಥ)",
    "(っ- ‸ - ς)♡",
    "(╥_╥)",
    "(ಥ_ಥ)ﾉ",
    "(｡╯︵╰｡)",
    "(；ω；)",
    "(இ﹏இ`｡)",
    "(╯︵╰,)",
    "(｡•́︿•̀｡)ﾉ",
    "(つд⊂)",
    "(っ╥╯﹏╰╥c)",
    "(╥﹏╥)ﾉ",
    "(◞‸◟；)",
    "(｡•́︵•̀｡)",
    "(｡ŏ﹏ŏ)",
    "(╯︵╰,)♡",
    "(ﾉД`)",
    "(இдஇ)",
    "(；へ：)",
    "(；´Д｀)",
    "( ´•̥̥̥ω•̥̥̥` )",
    "(๑•́ ₃ •̀๑)",
    "(╥ω╥)",
    "(ಥ﹏ಥ)♡",
    "(｡•́︿•̀｡)っ",
    "(｡•́ωก̀｡)",
    "(｡T ω T｡)",
    "(っ´；ω；`)っ"
};

static const char *success_messages[] = {
    "Nyaa~ flawless victory, senpai! ♡",
    "Purrfection achieved! The bytes are dancing~",
    "Yippee! Another function gets a gold star! ✧",
    "No bugs, only sparkles today! UwU",
    "Tiny paws, gigantic coding talent!",
    "You cooked, chef! The libc approves.",
    "Kawaii compiler noises intensify~",
    "Aww, this function is such a good bean!",
    "Sugoi! Not a single test could stop you!",
    "Meowgical execution! ♡",
    "This code deserves headpats. Lots of them.",
    "Bingo! Every test says yes, nya~",
    "The pointers are holding hands peacefully!",
    "Yay! Your function is officially adorable.",
    "A clean sweep! Have a virtual cookie.",
    "Sparkle sparkle, zero trouble! ✨",
    "This function passed the vibe check.",
    "The memory gods smile upon you today.",
    "Senpai, that was beautifully executed!",
    "Paws up! Another perfect run!",
    "UwU certified, bug-free edition!",
    "A tiny victory dance for a huge brain!",
    "Nyan~ your logic is looking mighty cute.",
    "Behold: a function with impeccable manners.",
    "All green! The terminal is blushing.",
    "Your code just earned a fluffy crown.",
    "The tests have surrendered peacefully.",
    "Mochi-level softness, steel-level correctness.",
    "Squeee! Everything matched the libc!",
    "This function gets unlimited cuddles.",
    "The stack is calm. The heap is happy.",
    "What a lovely day to pass every test!",
    "Yatta! You made the compiler proud.",
    "Even the semicolons are celebrating.",
    "One more function joins the cute club.",
    "That was smooth as a sleeping kitten.",
    "Perfect score! Deploy the confetti!",
    "Your algorithm just did a little happy dance.",
    "Blep! The Decimator is impressed.",
    "Mission accomplished, little code wizard!",
    "The bits lined up just for you, nya~",
    "No drama, just premium C craftsmanship.",
    "Your function is a certified sweetie pie.",
    "All tests passed. Now accept these headpats.",
    "Such elegance! Such grace! Such malloc!",
    "Green lights everywhere, senpai!",
    "The Decimator grants you one (1) hug.",
    "Aww yeah, another glorious clean run!",
    "Today the bugs chose to stay home.",
    "Your code is cute AND correct. Unfair advantage!"
};

static const char *failure_messages[] = {
    "Your code has the structural integrity of wet cardboard.",
    "That function just failed an open-book exam.",
    "Even a rubber duck would demand a refund.",
    "Congratulations, you invented the wrong answer.",
    "Your pointer has officially gone feral.",
    "The libc is filing a restraining order.",
    "That loop is a crime scene, not an algorithm.",
    "Your off-by-one just applied for citizenship.",
    "Baka. The bytes are not optional.",
    "Nyaa~ the compiler cannot save you from yourself.",
    "Your function speedran the humiliation category.",
    "The assertion has spoken. You lost.",
    "This is why the null terminator fears you.",
    "Your code has achieved negative charisma.",
    "Not even a miracle would make that result correct.",
    "Your algorithm is running on pure delusion.",
    "The stack has requested a new programmer.",
    "That condition belongs in a museum of mistakes.",
    "Your implementation is a bug with a function name.",
    "Your logic just tripped over a single byte.",
    "Skill issue confirmed. UwU.",
    "The Decimator is laughing at your expense.",
    "That output is aggressively incorrect.",
    "You lost to an integer. Impressive.",
    "The segmentation fairy says: absolutely not.",
    "Your function failed the vibe check AND the test.",
    "The return value is evidence against you.",
    "You wrote a bug and gave it a prototype.",
    "The bytes have unanimously voted you off the heap.",
    "Your code is an elaborate way to return nonsense.",
    "This assertion did not even break a sweat.",
    "Nyaa~ the standard library remains undefeated.",
    "Your indices are unsupervised and it shows.",
    "This is not debugging. This is archaeology.",
    "The test suite just issued a public execution.",
    "Even undefined behavior wants no part of this.",
    "Your code has been convicted of first-degree nonsense.",
    "The heap is considering legal action.",
    "Your result is so wrong it needs a warning label.",
    "That function is held together by misplaced confidence.",
    "Nyaa~ your branch prediction predicts disappointment.",
    "A single edge case just demolished your entire strategy.",
    "The Decimator does not negotiate with broken pointers.",
    "Your semicolons are innocent. The logic is not.",
    "That comparison belongs in the trash.",
    "Your code is losing an argument with a zero.",
    "This is the opposite of a flawless victory.",
    "You had one job. The bytes noticed.",
    "Your recursion is a staircase to nowhere.",
    "The Decimator sends no condolences."
};

/* ==================== TEST RUNNER ==================== */

static int total_passed = 0;
static int total_failed = 0;
static int function_passed = 0;
static int function_failed = 0;
static int test_number = 0;
static int show_passes = 1;
static int stop_on_failure = 0;
static int delay_between_tests = 7500;
static int delay_between_functions = 1200000;
static const char *current_function = "";

static int terminal_width(const char *text)
{
    mbstate_t state = {0};
    wchar_t character;
    size_t bytes;
    int width = 0;
    int character_width;

    while (*text)
    {
        bytes = mbrtowc(&character, text, MB_CUR_MAX, &state);
        if (bytes == (size_t)-1 || bytes == (size_t)-2 || bytes == 0)
        {
            width++;
            text++;
            memset(&state, 0, sizeof(state));
            continue;
        }
        character_width = wcwidth(character);
        if (character_width > 0)
            width += character_width;
        text += bytes;
    }
    return width;
}

static void pause_microseconds(int microseconds)
{
    struct timespec duration;

    if (microseconds <= 0)
        return;
    duration.tv_sec = microseconds / 1000000;
    duration.tv_nsec = (long)(microseconds % 1000000) * 1000;
    nanosleep(&duration, NULL);
}

static int read_delay(const char *name, int default_value)
{
    const char *value = getenv(name);
    char *end;
    long number;

    if (value == NULL || *value == '\0')
        return default_value;
    number = strtol(value, &end, 10);
    if (*end != '\0' || number < 0 || number > 2000000000L)
        return default_value;
    return (int)number;
}

static void check(const char *description, int passed)
{
    const char *face;
    const char *colour;
    int padding;

    if (test_number >= 30)
    {
        fprintf(stderr, "[TESTER ERROR] More than 30 tests for %s\n", current_function);
        exit(EXIT_FAILURE);
    }
    test_number++;
    if (passed)
    {
        total_passed++;
        function_passed++;
        face = success_kaomojis[rand() % COUNT(success_kaomojis)];
        colour = MINT;
    }
    else
    {
        total_failed++;
        function_failed++;
        face = failure_kaomojis[rand() % COUNT(failure_kaomojis)];
        colour = ROSE;
    }
    padding = 26 - terminal_width(face);
    if (padding < 1)
        padding = 1;
    if (!passed || show_passes)
        printf("%s[%s] %s%s%*s #%02d %s\n", colour,
            passed ? "PASS" : "FAIL", face, RESET,
            padding, "", test_number, description);
    if (!passed && stop_on_failure)
    {
        printf("%s%s%s\n", ROSE,
            failure_messages[rand() % COUNT(failure_messages)], RESET);
        exit(EXIT_FAILURE);
    }
    pause_microseconds(delay_between_tests);
}

static void run_test(const char *name, void (*test_function)(void))
{
    current_function = name;
    function_passed = 0;
    function_failed = 0;
    test_number = 0;
    printf("\n%s[TEST] %s%s\n", GOLD, name, RESET);
    test_function();
    printf("%s[COMPLETED]%s %-19s %s%2d PASS%s / %s%2d FAIL%s",
        GOLD, RESET, name, MINT, function_passed, RESET,
        function_failed ? ROSE : DIM, function_failed, RESET);
    if (function_failed == 0)
        printf("  %s", success_messages[rand() % COUNT(success_messages)]);
    putchar('\n');
    pause_microseconds(delay_between_functions);
}

/* ==================== SHARED TEST HELPERS ==================== */

static int same_sign(int left, int right)
{
    return ((left > 0) - (left < 0) == (right > 0) - (right < 0));
}

static void fill_pattern(unsigned char *buffer, size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        buffer[i] = (unsigned char)((i * 37 + 19) % 256);
        i++;
    }
}

static ssize_t read_written_bytes(FILE *file, unsigned char *buffer, size_t capacity)
{
    ssize_t count;

    if (file == NULL || lseek(fileno(file), 0, SEEK_SET) == -1)
        return -1;
    count = read(fileno(file), buffer, capacity);
    return count;
}

static void free_words(char **words)
{
    size_t i = 0;

    if (words == NULL)
        return;
    while (words[i] != NULL)
    {
        free(words[i]);
        i++;
    }
    free(words);
}

static int deleted_contents = 0;
static int visited_nodes = 0;

static void count_and_free(void *content)
{
    deleted_contents++;
    free(content);
}

static void increase_integer(void *content)
{
    visited_nodes++;
    (*(int *)content)++;
}

static void *double_integer(void *content)
{
    int *result = malloc(sizeof(int));

    if (result != NULL)
        *result = *(int *)content * 2;
    return result;
}

static char map_alternating(unsigned int index, char character)
{
    if (index % 2 == 0 && character >= 'a' && character <= 'z')
        return (char)(character - 'a' + 'A');
    return character;
}

static char map_index(unsigned int index, char character)
{
    return (char)(character + (char)(index % 3));
}

static void iter_alternating(unsigned int index, char *character)
{
    *character = map_alternating(index, *character);
}

static void iter_index(unsigned int index, char *character)
{
    *character = map_index(index, *character);
}

/* ==================== PART 1: CHARACTER FUNCTIONS ==================== */
void test_ft_isalpha(void)
{
    const int values[] = {-1, 0, 31, 32, 47, 48, 57, 64, 65, 66, 77,
        89, 90, 91, 96, 97, 98, 109, 121, 122, 123, 127, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (ASCII boundary)", values[i]);
        check(label, ft_isalpha(values[i]) == (isalpha(values[i]) != 0));
    }
}

void test_ft_isdigit(void)
{
    const int values[] = {-1, 0, 9, 10, 32, 43, 45, 46, 47, 48, 49,
        53, 56, 57, 58, 59, 64, 65, 90, 97, 122, 127, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (digit boundary)", values[i]);
        check(label, ft_isdigit(values[i]) == (isdigit(values[i]) != 0));
    }
}

void test_ft_isalnum(void)
{
    const int values[] = {-1, 0, 9, 31, 32, 33, 47, 48, 53, 57, 58,
        64, 65, 77, 90, 91, 96, 97, 109, 122, 123, 126, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (letter or digit)", values[i]);
        check(label, ft_isalnum(values[i]) == (isalnum(values[i]) != 0));
    }
}

void test_ft_isascii(void)
{
    const int values[] = {-1, 0, 1, 7, 8, 9, 10, 13, 31, 32, 48,
        57, 65, 90, 97, 122, 125, 126, 127, 128, 129, 200, 254, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (ASCII range)", values[i]);
        check(label, ft_isascii(values[i]) == (values[i] >= 0 && values[i] <= 127));
    }
}

void test_ft_isprint(void)
{
    const int values[] = {-1, 0, 1, 7, 8, 9, 10, 13, 30, 31, 32,
        33, 34, 48, 57, 65, 90, 97, 122, 125, 126, 127, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (printable range)", values[i]);
        check(label, ft_isprint(values[i]) == (isprint(values[i]) != 0));
    }
}

void test_ft_toupper(void)
{
    const int values[] = {-1, 0, 9, 32, 47, 48, 57, 64, 65, 77, 90,
        91, 96, 97, 98, 102, 109, 113, 121, 122, 123, 127, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (uppercase conversion)", values[i]);
        check(label, ft_toupper(values[i]) == toupper(values[i]));
    }
}

void test_ft_tolower(void)
{
    const int values[] = {-1, 0, 9, 32, 47, 48, 57, 64, 65, 66, 70,
        77, 81, 89, 90, 91, 96, 97, 109, 122, 123, 127, 128, 255};
    char label[80];
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(label, sizeof(label), "character=%d (lowercase conversion)", values[i]);
        check(label, ft_tolower(values[i]) == tolower(values[i]));
    }
}

/* ==================== PART 1: STRING AND MEMORY ==================== */

void test_ft_strlen(void)
{
    const char *inputs[] = {"", "a", "Z", "0", " ", "\t", "\n", "abc",
        "123456789", "hello world", "   ", "line\nline", "a\tb", "a\0hidden",
        "Lorem ipsum dolor sit amet", "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUV", "\xff\x80\x01", "C programming!"};
    char label[90];
    size_t i;

    for (i = 0; i < COUNT(inputs); i++)
    {
        snprintf(label, sizeof(label), "input #%zu, expected length=%zu",
            i + 1, strlen(inputs[i]));
        check(label, ft_strlen(inputs[i]) == strlen(inputs[i]));
    }
}

void test_ft_memset(void)
{
    struct case_data { size_t offset; size_t length; int value; };
    const struct case_data cases[] = {
        {0, 0, 0}, {0, 1, 0}, {0, 1, 255}, {0, 8, 42},
        {0, 64, 0}, {0, 64, 255}, {1, 1, -1}, {1, 63, 65},
        {5, 10, 128}, {8, 1, 'X'}, {8, 16, 7}, {12, 20, 0},
        {16, 32, 256}, {31, 1, -128}, {31, 33, 32},
        {63, 1, 127}, {63, 0, 123}
    };
    unsigned char actual[64];
    unsigned char expected[64];
    void *returned;
    char label[100];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        fill_pattern(actual, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        returned = ft_memset(actual + cases[i].offset, cases[i].value, cases[i].length);
        memset(expected + cases[i].offset, cases[i].value, cases[i].length);
        snprintf(label, sizeof(label), "offset=%zu, bytes=%zu, value=%d",
            cases[i].offset, cases[i].length, cases[i].value);
        check(label, returned == actual + cases[i].offset
            && memcmp(actual, expected, sizeof(actual)) == 0);
    }
}

void test_ft_bzero(void)
{
    struct case_data { size_t offset; size_t length; };
    const struct case_data cases[] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 8}, {0, 32}, {0, 63},
        {0, 64}, {1, 1}, {1, 63}, {2, 17}, {7, 9},
        {10, 1}, {16, 16}, {30, 30}, {31, 1}, {32, 32},
        {62, 2}, {63, 1}, {63, 0}
    };
    unsigned char actual[64];
    unsigned char expected[64];
    char label[90];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        fill_pattern(actual, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        ft_bzero(actual + cases[i].offset, cases[i].length);
        bzero(expected + cases[i].offset, cases[i].length);
        snprintf(label, sizeof(label), "offset=%zu, bytes=%zu",
            cases[i].offset, cases[i].length);
        check(label, memcmp(actual, expected, sizeof(actual)) == 0);
    }
}

void test_ft_memcpy(void)
{
    struct case_data { size_t destination; size_t source; size_t length; };
    const struct case_data cases[] = {
        {0, 0, 0}, {0, 0, 1}, {0, 0, 64}, {1, 2, 1},
        {2, 4, 4}, {5, 6, 17}, {0, 3, 32}, {12, 0, 20},
        {32, 32, 32}, {60, 60, 4}, {63, 63, 1},
        {0, 10, 54}, {10, 0, 54}, {16, 16, 32}, {63, 63, 0}
    };
    unsigned char source[64];
    unsigned char actual[64];
    unsigned char expected[64];
    void *returned;
    char label[110];
    size_t i;

    fill_pattern(source, sizeof(source));
    for (i = 0; i < COUNT(cases); i++)
    {
        memset(actual, 0xA5, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        returned = ft_memcpy(actual + cases[i].destination,
            source + cases[i].source, cases[i].length);
        memcpy(expected + cases[i].destination,
            source + cases[i].source, cases[i].length);
        snprintf(label, sizeof(label), "dst=%zu, src=%zu, bytes=%zu",
            cases[i].destination, cases[i].source, cases[i].length);
        check(label, returned == actual + cases[i].destination
            && memcmp(actual, expected, sizeof(actual)) == 0);
    }
}

void test_ft_memmove(void)
{
    struct case_data { size_t destination; size_t source; size_t length; };
    const struct case_data cases[] = {
        {0, 0, 0}, {0, 0, 1}, {0, 0, 64}, {1, 0, 1},
        {1, 0, 10}, {1, 0, 63}, {5, 0, 30}, {10, 0, 40},
        {31, 0, 32}, {0, 1, 1}, {0, 1, 10}, {0, 1, 63},
        {0, 5, 30}, {0, 10, 40}, {0, 31, 32},
        {32, 0, 32}, {0, 32, 32}, {12, 12, 20},
        {63, 63, 1}, {63, 63, 0}
    };
    unsigned char actual[64];
    unsigned char expected[64];
    void *returned;
    char label[110];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        fill_pattern(actual, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        returned = ft_memmove(actual + cases[i].destination,
            actual + cases[i].source, cases[i].length);
        memmove(expected + cases[i].destination,
            expected + cases[i].source, cases[i].length);
        snprintf(label, sizeof(label), "dst=%zu, src=%zu, bytes=%zu",
            cases[i].destination, cases[i].source, cases[i].length);
        check(label, returned == actual + cases[i].destination
            && memcmp(actual, expected, sizeof(actual)) == 0);
    }
}

void test_ft_strchr(void)
{
    struct case_data { const char *text; int character; const char *name; };
    const struct case_data cases[] = {
        {"", 'a', "empty / missing"}, {"", 0, "empty / NUL"},
        {"abc", 'a', "first byte"}, {"abc", 'b', "middle byte"},
        {"abc", 'c', "last byte"}, {"abc", 0, "terminating NUL"},
        {"abc", 'z', "absent byte"}, {"banana", 'a', "repeated / first"},
        {"banana", 'n', "repeated / middle"}, {"aaaa", 'a', "all equal"},
        {"hello world", ' ', "space"}, {"x\ny", '\n', "newline"},
        {"a\xffz", 255, "high byte"}, {"a\x80z", 128, "byte 128"},
        {"abc", 256 + 'b', "char conversion"}, {"x", 'x', "single match"},
        {"x", 'y', "single missing"}, {"abc", -1, "negative converted byte"}
    };
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
        check(cases[i].name,
            ft_strchr(cases[i].text, cases[i].character)
            == strchr(cases[i].text, cases[i].character));
}

void test_ft_strrchr(void)
{
    struct case_data { const char *text; int character; const char *name; };
    const struct case_data cases[] = {
        {"", 'a', "empty / missing"}, {"", 0, "empty / NUL"},
        {"abc", 'a', "first byte"}, {"abc", 'b', "middle byte"},
        {"abc", 'c', "last byte"}, {"abc", 0, "terminating NUL"},
        {"abc", 'z', "absent byte"}, {"banana", 'a', "repeated / last"},
        {"banana", 'n', "repeated / last n"}, {"aaaa", 'a', "all equal / last"},
        {"hello world", 'l', "many matches"}, {"x\ny", '\n', "newline"},
        {"a\xffz", 255, "high byte"}, {"a\x80z", 128, "byte 128"},
        {"abc", 256 + 'b', "char conversion"}, {"x", 'x', "single match"},
        {"x", 'y', "single missing"}, {"abc", -1, "negative converted byte"}
    };
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
        check(cases[i].name,
            ft_strrchr(cases[i].text, cases[i].character)
            == strrchr(cases[i].text, cases[i].character));
}

void test_ft_strncmp(void)
{
    struct case_data { const char *a; const char *b; size_t n; const char *name; };
    const struct case_data cases[] = {
        {"", "", 0, "empty / n=0"}, {"", "", 5, "empty / n=5"},
        {"a", "b", 0, "different / n=0"}, {"a", "b", 1, "first byte less"},
        {"b", "a", 1, "first byte greater"},
        {"abc", "abc", 3, "equal / exact n"},
        {"abc", "abc", 100, "equal / large n"},
        {"abc", "abcd", 4, "first string shorter"},
        {"abcd", "abc", 4, "second string shorter"},
        {"abcX", "abcY", 3, "difference after n"},
        {"abcX", "abcY", 4, "difference at n"},
        {"abcX", "abcY", 5, "difference before n"},
        {"abz", "aba", 3, "last byte greater"},
        {"aba", "abz", 3, "last byte less"},
        {"\xff", "\x01", 1, "unsigned byte 255"},
        {"\x01", "\xff", 1, "unsigned byte 1"},
        {"a\0z", "a\0x", 4, "stop on NUL"},
        {"", "a", 1, "empty versus nonempty"},
        {"a", "", 1, "nonempty versus empty"},
        {"abc", "abd", 2, "difference just outside n"}
    };
    char label[100];
    int actual;
    int expected;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        actual = ft_strncmp(cases[i].a, cases[i].b, cases[i].n);
        expected = strncmp(cases[i].a, cases[i].b, cases[i].n);
        snprintf(label, sizeof(label), "%s, n=%zu", cases[i].name, cases[i].n);
        check(label, same_sign(actual, expected));
    }
}

void test_ft_memchr(void)
{
    const unsigned char bytes[] = {0, 1, 2, 255, 'a', 'b', 'a', 128, 0, 42, 42};
    struct case_data { size_t offset; size_t length; int value; const char *name; };
    const struct case_data cases[] = {
        {0, 0, 0, "zero-length search"}, {0, 1, 0, "first byte NUL"},
        {0, 3, 2, "last byte in range"}, {0, 2, 2, "just outside range"},
        {0, 11, 255, "byte 255"}, {0, 11, 128, "byte 128"},
        {0, 11, 'a', "first repeated a"}, {4, 4, 'a', "second repeated a"},
        {0, 11, 'z', "not found"}, {8, 3, 0, "NUL in suffix"},
        {9, 2, 42, "repeat at end"}, {10, 1, 42, "last possible byte"},
        {10, 0, 42, "zero length at end"}, {0, 11, 256, "256 becomes NUL"},
        {0, 11, -1, "-1 becomes 255"}, {7, 4, 128, "match at offset"},
        {1, 5, 0, "NUL before start"}, {2, 3, 1, "match before start"},
        {10, 0, 0, "last-byte pointer with n=0"}
    };
    char label[100];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        snprintf(label, sizeof(label), "%s (offset=%zu, n=%zu)",
            cases[i].name, cases[i].offset, cases[i].length);
        check(label, ft_memchr(bytes + cases[i].offset,
            cases[i].value, cases[i].length)
            == memchr(bytes + cases[i].offset, cases[i].value, cases[i].length));
    }
}

void test_ft_memcmp(void)
{
    struct case_data { size_t difference; size_t length; int change; const char *name; };
    const struct case_data cases[] = {
        {0, 0, 1, "zero-length"}, {0, 1, 1, "difference first byte"},
        {1, 1, 1, "difference just after range"},
        {1, 2, -1, "difference second byte"},
        {3, 3, 1, "difference just after n"},
        {3, 4, 1, "difference at last byte"},
        {7, 8, -1, "difference in prefix"},
        {15, 16, 1, "difference at boundary"},
        {16, 16, 1, "difference outside boundary"},
        {31, 32, 1, "difference at 32"},
        {32, 32, 1, "difference outside 32"},
        {63, 64, -1, "difference last byte"},
        {0, 64, 0, "equal full buffers"},
        {8, 64, 0, "equal with many bytes"},
        {0, 64, 1, "different at first byte"},
        {0, 64, -1, "first byte reversed"},
        {20, 64, 1, "middle byte greater"},
        {20, 64, -1, "middle byte lower"}
    };
    unsigned char a[64];
    unsigned char b[64];
    char label[100];
    int actual;
    int expected;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        fill_pattern(a, sizeof(a));
        memcpy(b, a, sizeof(a));
        b[cases[i].difference] = (unsigned char)(a[cases[i].difference] + cases[i].change);
        actual = ft_memcmp(a, b, cases[i].length);
        expected = memcmp(a, b, cases[i].length);
        snprintf(label, sizeof(label), "%s, n=%zu", cases[i].name, cases[i].length);
        check(label, same_sign(actual, expected));
    }
}

void test_ft_atoi(void)
{
    const char *inputs[] = {
        "", "0", "1", "-1", "+1", "42", "-42", "00042",
        "-00042", "  42", "\t42", "\n42", "\v42", "\f42",
        "\r42", " \t\n-123", "123abc", "-123abc", "12 34",
        "+0", "-0", "2147483647", "-2147483648",
        "  +0012", "++1", "--1", "+-1", "0x10", "42-12", "abc"
    };
    const char *names[] = {
        "empty input", "zero", "positive one", "negative one", "plus sign",
        "positive 42", "negative 42", "leading zeroes",
        "negative leading zeroes", "leading spaces", "leading tab",
        "leading newline", "leading vertical tab", "leading form feed",
        "leading carriage return", "mixed whitespace", "trailing letters",
        "negative with trailing letters", "space after digits",
        "positive signed zero", "negative signed zero", "INT_MAX",
        "INT_MIN", "spaces, plus and zeroes", "two plus signs",
        "two minus signs", "mixed signs", "hex-like prefix",
        "minus after digits", "no digits"
    };
    char label[100];
    size_t i;

    for (i = 0; i < COUNT(inputs); i++)
    {
        snprintf(label, sizeof(label), "%s, expected=%d", names[i], atoi(inputs[i]));
        check(label, ft_atoi(inputs[i]) == atoi(inputs[i]));
    }
}

void test_ft_calloc(void)
{
    struct case_data { size_t count; size_t size; const char *name; };
    const struct case_data cases[] = {
        {0, 0, "both zero"}, {0, 1, "zero count"},
        {1, 0, "zero size"}, {10, 0, "many zero-sized elements"},
        {0, 100, "zero count / large size"}, {1, 1, "one byte"},
        {2, 1, "two bytes"}, {1, 64, "one 64-byte block"},
        {4, 4, "four ints"}, {3, 7, "odd dimensions"},
        {16, 16, "256 bytes"}, {100, 1, "100 bytes"},
        {1, 1024, "one kilobyte"}, {64, 64, "four kilobytes"},
        {257, 3, "odd total"}, {20, 17, "non-power-of-two"}
    };
    const size_t max_value = (size_t)-1;
    unsigned char *memory;
    size_t bytes;
    size_t j;
    size_t i;
    char label[120];
    int all_zero;

    for (i = 0; i < COUNT(cases); i++)
    {
        bytes = cases[i].count * cases[i].size;
        memory = ft_calloc(cases[i].count, cases[i].size);
        all_zero = memory != NULL;
        j = 0;
        while (all_zero && j < bytes)
        {
            if (memory[j] != 0)
                all_zero = 0;
            j++;
        }
        snprintf(label, sizeof(label), "%s (%zu x %zu)",
            cases[i].name, cases[i].count, cases[i].size);
        check(label, all_zero);
        free(memory);
    }
    memory = ft_calloc(max_value, 2);
    check("overflow: SIZE_MAX x 2 must return NULL", memory == NULL);
    free(memory);
    memory = ft_calloc(max_value / 2 + 1, 2);
    check("overflow to zero: (SIZE_MAX/2+1) x 2", memory == NULL);
    free(memory);
    memory = ft_calloc(max_value / 16 + 1, 16);
    check("overflow: (SIZE_MAX/16+1) x 16", memory == NULL);
    free(memory);
}

void test_ft_strdup(void)
{
    const char *inputs[] = {
        "", "a", "Z", "0", " ", "\n", "\t", "abc", "ABC",
        "123", "hello", "hello world", "a b c", "abc\nxyz",
        "42 Lausanne", "!@#$%^&*", "Aa0!", "line\nline",
        "0123456789", "C programming", "The quick brown fox"
    };
    char *copy;
    char label[100];
    size_t i;

    for (i = 0; i < COUNT(inputs); i++)
    {
        copy = ft_strdup(inputs[i]);
        snprintf(label, sizeof(label), "input #%zu, length=%zu, independent copy",
            i + 1, strlen(inputs[i]));
        check(label, copy != NULL && copy != inputs[i]
            && strcmp(copy, inputs[i]) == 0);
        free(copy);
    }
}

/* ==================== PART 2: ALLOCATED STRINGS ==================== */

void test_ft_substr(void)
{
    struct case_data { const char *input; unsigned int start; size_t length;
        const char *expected; const char *name; };
    const struct case_data cases[] = {
        {"", 0, 0, "", "empty string / zero length"},
        {"", 0, 5, "", "empty string / large length"},
        {"abc", 0, 0, "", "zero length"},
        {"abc", 0, 1, "a", "first byte"},
        {"abc", 1, 1, "b", "middle byte"},
        {"abc", 2, 1, "c", "last byte"},
        {"abc", 0, 3, "abc", "whole string"},
        {"abc", 0, 100, "abc", "length larger than string"},
        {"abc", 1, 100, "bc", "middle to end"},
        {"abc", 2, 2, "c", "partial last byte"},
        {"abc", 3, 5, "", "start at terminator"},
        {"abc", 4, 5, "", "start after terminator"},
        {"abc", 100, 5, "", "start far beyond end"},
        {"hello world", 6, 5, "world", "second word"},
        {"hello world", 1, 4, "ello", "middle segment"},
        {"a b c", 1, 3, " b ", "spaces preserved"},
        {"abc\ndef", 3, 2, "\nd", "newline in segment"},
        {"abcdef", 5, 0, "", "zero length near end"},
        {"x", UINT_MAX, 50, "", "very large start"},
        {"0123456789", 7, 3, "789", "last three digits"}
    };
    char *actual;
    char label[120];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        actual = ft_substr(cases[i].input, cases[i].start, cases[i].length);
        snprintf(label, sizeof(label), "%s (start=%u, len=%zu)",
            cases[i].name, cases[i].start, cases[i].length);
        check(label, actual != NULL && strcmp(actual, cases[i].expected) == 0);
        free(actual);
    }
}

void test_ft_strjoin(void)
{
    struct case_data { const char *left; const char *right; const char *expected;
        const char *name; };
    const struct case_data cases[] = {
        {"", "", "", "both empty"},
        {"a", "", "a", "right empty"},
        {"", "z", "z", "left empty"},
        {"a", "b", "ab", "one plus one"},
        {"abc", "def", "abcdef", "two words"},
        {"hello ", "world", "hello world", "with space"},
        {"42", "!", "42!", "number and punctuation"},
        {" ", " ", "  ", "two spaces"},
        {"\n", "line", "\nline", "newline on left"},
        {"line", "\n", "line\n", "newline on right"},
        {"a\tb", "\tc", "a\tb\tc", "tabs"},
        {"0123456789", "abcdefghij", "0123456789abcdefghij", "long pair"},
        {"prefix", "suffix", "prefixsuffix", "simple suffix"},
        {"abc", "abc", "abcabc", "repeated contents"},
        {"x", "longer right-hand string", "xlonger right-hand string", "uneven sizes"},
        {"UPPER", "lower", "UPPERlower", "mixed case"}
    };
    char *joined;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        joined = ft_strjoin(cases[i].left, cases[i].right);
        check(cases[i].name, joined != NULL
            && strcmp(joined, cases[i].expected) == 0);
        free(joined);
    }
}

void test_ft_strtrim(void)
{
    struct case_data { const char *input; const char *set;
        const char *expected; const char *name; };
    const struct case_data cases[] = {
        {"", " ", "", "empty input"},
        {"abc", "", "abc", "empty set"},
        {"abc", " ", "abc", "nothing to trim"},
        {" abc", " ", "abc", "trim left"},
        {"abc ", " ", "abc", "trim right"},
        {" abc ", " ", "abc", "trim both"},
        {"   abc   ", " ", "abc", "many spaces"},
        {"   ", " ", "", "everything removed"},
        {"a", "a", "", "single removed"},
        {"aaa", "a", "", "all repeated removed"},
        {"xxabcxx", "x", "abc", "one trim character"},
        {"xyabcxy", "xy", "abc", "two trim characters"},
        {"xyabcxy", "yx", "abc", "set order irrelevant"},
        {"abcabc", "abc", "", "all from multi-char set"},
        {"123hello321", "123", "hello", "numeric trim set"},
        {"!!hello??", "!?", "hello", "punctuation set"},
        {"\t\nword\n\t", "\t\n", "word", "tabs and newlines"},
        {"..a..b..", ".", "a..b", "keep internal dots"},
        {"abXba", "ab", "X", "keep middle byte"},
        {"hello", "xyz", "hello", "unmatched set"},
        {"-h-e-l-l-o-", "-", "h-e-l-l-o", "keep internal dashes"},
        {" a b ", " ", "a b", "keep internal spaces"},
        {"a b c", "c", "a b ", "preserve trailing space"},
        {"ab", "a", "b", "remove only first byte"}
    };
    char *trimmed;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        trimmed = ft_strtrim(cases[i].input, cases[i].set);
        check(cases[i].name, trimmed != NULL
            && strcmp(trimmed, cases[i].expected) == 0);
        free(trimmed);
    }
}

void test_ft_split(void)
{
    struct case_data { const char *input; char separator;
        const char *expected[12]; const char *name; };
    const struct case_data cases[] = {
        {"", ',', {NULL}, "empty string"},
        {",,,", ',', {NULL}, "only separators"},
        {"abc", ',', {"abc", NULL}, "no separators"},
        {"a,b,c", ',', {"a", "b", "c", NULL}, "three words"},
        {"a,,b,c", ',', {"a", "b", "c", NULL}, "consecutive separators"},
        {",a,b,", ',', {"a", "b", NULL}, "edge separators"},
        {"a", 'a', {NULL}, "single separator"},
        {"  hello   world  ", ' ', {"hello", "world", NULL}, "many spaces"},
        {"a b c", ' ', {"a", "b", "c", NULL}, "single spaces"},
        {"a:b:c", ':', {"a", "b", "c", NULL}, "colon"},
        {"no delimiter", ',', {"no delimiter", NULL}, "unmatched separator"},
        {"aa--bb----cc", '-', {"aa", "bb", "cc", NULL}, "dash groups"},
        {"0|1|2|3", '|', {"0", "1", "2", "3", NULL}, "pipe"},
        {"x\ty\tz", '\t', {"x", "y", "z", NULL}, "tab"},
        {"a\nb\n\nc", '\n', {"a", "b", "c", NULL}, "newline"},
        {"abc", '\0', {"abc", NULL}, "NUL separator"},
        {"a,,,b,,,c", ',', {"a", "b", "c", NULL}, "separator clusters"},
        {"one", 'e', {"on", NULL}, "separator at end"},
        {"eone", 'e', {"on", NULL}, "separator at both ends"},
        {"a,b,c,d,e,f,g,h", ',', {"a", "b", "c", "d", "e", "f", "g", "h", NULL}, "eight words"}
    };
    char **words;
    int passed;
    size_t j;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        words = ft_split(cases[i].input, cases[i].separator);
        passed = words != NULL;
        j = 0;
        while (passed && cases[i].expected[j] != NULL)
        {
            if (words[j] == NULL || strcmp(words[j], cases[i].expected[j]) != 0)
                passed = 0;
            j++;
        }
        if (passed && words[j] != NULL)
            passed = 0;
        check(cases[i].name, passed);
        free_words(words);
    }
}

void test_ft_itoa(void)
{
    const int values[] = {0, 1, -1, 9, -9, 10, -10, 11, -11,
        42, -42, 99, -99, 100, -100, 101, -101, 999, -999,
        1000, -1000, 12345, -12345, 999999, -999999,
        123456789, -123456789, INT_MIN, INT_MAX};
    char expected[40];
    char label[90];
    char *actual;
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        snprintf(expected, sizeof(expected), "%d", values[i]);
        snprintf(label, sizeof(label), "integer=%d, expected=%s", values[i], expected);
        actual = ft_itoa(values[i]);
        check(label, actual != NULL && strcmp(actual, expected) == 0);
        free(actual);
    }
}

/* ==================== PART 2: STRING CALLBACKS ==================== */

void test_ft_strmapi(void)
{
    struct case_data { const char *input; const char *expected;
        char (*callback)(unsigned int, char); const char *name; };
    const struct case_data cases[] = {
        {"", "", map_alternating, "empty / alternating uppercase"},
        {"a", "A", map_alternating, "single lowercase"},
        {"b", "B", map_alternating, "different single lowercase"},
        {"ab", "Ab", map_alternating, "two letters"},
        {"abc", "AbC", map_alternating, "three letters"},
        {"abcdef", "AbCdEf", map_alternating, "six letters"},
        {"hello world", "HeLlO WoRlD", map_alternating, "spaces and letters"},
        {"42", "42", map_alternating, "digits unchanged"},
        {"A0z9", "A0Z9", map_alternating, "mixed uppercase/digits"},
        {"", "", map_index, "empty / add index"},
        {"a", "a", map_index, "first index is zero"},
        {"abc", "ace", map_index, "index modulo three"},
        {"aaaaaa", "abcabc", map_index, "index pattern repeats"},
        {"012345", "024357", map_index, "numeric characters"},
        {"!!!!", "!\"#!", map_index, "punctuation with index"}
    };
    char *actual;
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        actual = ft_strmapi(cases[i].input, cases[i].callback);
        check(cases[i].name, actual != NULL
            && strcmp(actual, cases[i].expected) == 0);
        free(actual);
    }
}

void test_ft_striteri(void)
{
    struct case_data { const char *input; const char *expected;
        void (*callback)(unsigned int, char *); const char *name; };
    const struct case_data cases[] = {
        {"", "", iter_alternating, "empty / alternating uppercase"},
        {"a", "A", iter_alternating, "single lowercase"},
        {"b", "B", iter_alternating, "different single lowercase"},
        {"ab", "Ab", iter_alternating, "two letters"},
        {"abc", "AbC", iter_alternating, "three letters"},
        {"abcdef", "AbCdEf", iter_alternating, "six letters"},
        {"hello world", "HeLlO WoRlD", iter_alternating, "spaces and letters"},
        {"42", "42", iter_alternating, "digits unchanged"},
        {"A0z9", "A0Z9", iter_alternating, "mixed uppercase/digits"},
        {"", "", iter_index, "empty / add index"},
        {"a", "a", iter_index, "first index is zero"},
        {"abc", "ace", iter_index, "index modulo three"},
        {"aaaaaa", "abcabc", iter_index, "index pattern repeats"},
        {"012345", "024357", iter_index, "numeric characters"},
        {"!!!!", "!\"#!", iter_index, "punctuation with index"}
    };
    char actual[128];
    size_t i;

    for (i = 0; i < COUNT(cases); i++)
    {
        strcpy(actual, cases[i].input);
        ft_striteri(actual, cases[i].callback);
        check(cases[i].name, strcmp(actual, cases[i].expected) == 0);
    }
}

/* ==================== PART 2: FILE DESCRIPTORS ==================== */

void test_ft_putchar_fd(void)
{
    const unsigned char characters[] = {0, 1, 9, 10, 13, 32, 'A', 'z', '0', '!', 127, 255};
    FILE *file;
    unsigned char actual[32];
    ssize_t length;
    char label[90];
    size_t i;

    for (i = 0; i < COUNT(characters); i++)
    {
        file = tmpfile();
        if (file == NULL)
        {
            check("tmpfile() failed", 0);
            return;
        }
        ft_putchar_fd((char)characters[i], fileno(file));
        length = read_written_bytes(file, actual, sizeof(actual));
        snprintf(label, sizeof(label), "byte value=%u", characters[i]);
        check(label, length == 1 && actual[0] == characters[i]);
        fclose(file);
    }
}

void test_ft_putstr_fd(void)
{
    const char *inputs[] = {"", "a", "Z", "0", " ", "\n", "abc",
        "hello world", "42", "a\tb", "two\nlines", "0123456789",
        "Symbols: !@#$%^&*", "The quick brown fox"};
    FILE *file;
    unsigned char actual[256];
    ssize_t length;
    char label[90];
    size_t i;

    for (i = 0; i < COUNT(inputs); i++)
    {
        file = tmpfile();
        if (file == NULL)
        {
            check("tmpfile() failed", 0);
            return;
        }
        ft_putstr_fd((char *)inputs[i], fileno(file));
        length = read_written_bytes(file, actual, sizeof(actual));
        snprintf(label, sizeof(label), "input #%zu, bytes=%zu", i + 1, strlen(inputs[i]));
        check(label, length == (ssize_t)strlen(inputs[i])
            && memcmp(actual, inputs[i], strlen(inputs[i])) == 0);
        fclose(file);
    }
}

void test_ft_putendl_fd(void)
{
    const char *inputs[] = {"", "a", "Z", "0", " ", "\n", "abc",
        "hello world", "42", "a\tb", "two\nlines", "0123456789",
        "Symbols: !@#$%^&*", "The quick brown fox"};
    FILE *file;
    unsigned char actual[256];
    ssize_t length;
    size_t input_length;
    char label[100];
    size_t i;

    for (i = 0; i < COUNT(inputs); i++)
    {
        file = tmpfile();
        if (file == NULL)
        {
            check("tmpfile() failed", 0);
            return;
        }
        ft_putendl_fd((char *)inputs[i], fileno(file));
        length = read_written_bytes(file, actual, sizeof(actual));
        input_length = strlen(inputs[i]);
        snprintf(label, sizeof(label), "input #%zu, includes final newline", i + 1);
        check(label, length == (ssize_t)(input_length + 1)
            && memcmp(actual, inputs[i], input_length) == 0
            && actual[input_length] == '\n');
        fclose(file);
    }
}

void test_ft_putnbr_fd(void)
{
    const int values[] = {0, 1, -1, 9, -9, 10, -10, 42, -42,
        99, -99, 100, -100, 1000, -1000, 123456,
        -123456, INT_MIN, INT_MAX};
    FILE *file;
    unsigned char actual[64];
    char expected[64];
    char label[100];
    ssize_t length;
    size_t i;

    for (i = 0; i < COUNT(values); i++)
    {
        file = tmpfile();
        if (file == NULL)
        {
            check("tmpfile() failed", 0);
            return;
        }
        snprintf(expected, sizeof(expected), "%d", values[i]);
        ft_putnbr_fd(values[i], fileno(file));
        length = read_written_bytes(file, actual, sizeof(actual));
        snprintf(label, sizeof(label), "integer=%d, expected=%s", values[i], expected);
        check(label, length == (ssize_t)strlen(expected)
            && memcmp(actual, expected, strlen(expected)) == 0);
        fclose(file);
    }
}

/* ==================== BONUS: LINKED LISTS ==================== */

void test_ft_lstnew(void)
{
    int numbers[] = {0, 1, -1, 42, -42, INT_MIN, INT_MAX};
    const char *texts[] = {"", "hello", "a", "longer string"};
    void *contents[12];
    t_list *node;
    char label[80];
    size_t i;

    contents[0] = NULL;
    for (i = 0; i < COUNT(numbers); i++)
        contents[i + 1] = &numbers[i];
    for (i = 0; i < COUNT(texts); i++)
        contents[i + 1 + COUNT(numbers)] = (void *)texts[i];
    for (i = 0; i < COUNT(contents); i++)
    {
        node = ft_lstnew(contents[i]);
        snprintf(label, sizeof(label), "content pointer #%zu (next must be NULL)", i + 1);
        check(label, node != NULL && node->content == contents[i]
            && node->next == NULL);
        free(node);
    }
}

void test_ft_lstadd_front(void)
{
    t_list nodes[11];
    t_list *head;
    t_list *current;
    size_t length;
    size_t j;
    int passed;
    char label[80];

    for (length = 0; length <= 10; length++)
    {
        head = NULL;
        for (j = 0; j < length; j++)
        {
            nodes[j].content = &nodes[j];
            nodes[j].next = NULL;
            ft_lstadd_front(&head, &nodes[j]);
        }
        passed = 1;
        current = head;
        for (j = 0; j < length; j++)
        {
            if (current != &nodes[length - 1 - j])
            {
                passed = 0;
                break;
            }
            current = current->next;
        }
        if (passed && current != NULL)
            passed = 0;
        snprintf(label, sizeof(label), "prepend %zu nodes: reverse order", length);
        check(label, passed);
    }
}

void test_ft_lstsize(void)
{
    t_list nodes[16];
    size_t length;
    size_t j;
    char label[80];

    for (length = 0; length <= COUNT(nodes); length++)
    {
        for (j = 0; j < length; j++)
        {
            nodes[j].content = NULL;
            nodes[j].next = j + 1 < length ? &nodes[j + 1] : NULL;
        }
        snprintf(label, sizeof(label), "list contains %zu nodes", length);
        check(label, ft_lstsize(length ? &nodes[0] : NULL) == length);
    }
}

void test_ft_lstlast(void)
{
    t_list nodes[16];
    size_t length;
    size_t j;
    char label[80];

    for (length = 0; length <= COUNT(nodes); length++)
    {
        for (j = 0; j < length; j++)
        {
            nodes[j].content = NULL;
            nodes[j].next = j + 1 < length ? &nodes[j + 1] : NULL;
        }
        snprintf(label, sizeof(label), "last node of a %zu-node list", length);
        check(label, ft_lstlast(length ? &nodes[0] : NULL)
            == (length ? &nodes[length - 1] : NULL));
    }
}

void test_ft_lstadd_back(void)
{
    t_list nodes[11];
    t_list *head;
    t_list *current;
    size_t length;
    size_t j;
    int passed;
    char label[80];

    for (length = 0; length <= 10; length++)
    {
        head = NULL;
        for (j = 0; j < length; j++)
        {
            nodes[j].content = &nodes[j];
            nodes[j].next = NULL;
            ft_lstadd_back(&head, &nodes[j]);
        }
        passed = 1;
        current = head;
        for (j = 0; j < length; j++)
        {
            if (current != &nodes[j])
            {
                passed = 0;
                break;
            }
            current = current->next;
        }
        if (passed && current != NULL)
            passed = 0;
        snprintf(label, sizeof(label), "append %zu nodes: insertion order", length);
        check(label, passed);
    }
}

void test_ft_lstdelone(void)
{
    t_list *node;
    int *content;
    char label[80];
    size_t i;

    for (i = 0; i < 10; i++)
    {
        node = malloc(sizeof(t_list));
        content = i == 0 ? NULL : malloc(sizeof(int));
        if (node == NULL || (i > 0 && content == NULL))
        {
            free(node);
            free(content);
            check("test setup allocation failed", 0);
            return;
        }
        if (content != NULL)
            *content = (int)i * 17;
        node->content = content;
        node->next = NULL;
        deleted_contents = 0;
        ft_lstdelone(node, count_and_free);
        snprintf(label, sizeof(label), "delete node #%zu, call del exactly once", i + 1);
        check(label, deleted_contents == 1);
    }
}

void test_ft_lstclear(void)
{
    t_list *head;
    t_list *node;
    t_list *previous;
    int *content;
    size_t length;
    size_t j;
    int created;
    char label[80];

    for (length = 0; length <= 9; length++)
    {
        head = NULL;
        previous = NULL;
        created = 1;
        for (j = 0; j < length; j++)
        {
            node = malloc(sizeof(t_list));
            content = malloc(sizeof(int));
            if (node == NULL || content == NULL)
            {
                free(node);
                free(content);
                created = 0;
                break;
            }
            *content = (int)j;
            node->content = content;
            node->next = NULL;
            if (previous == NULL)
                head = node;
            else
                previous->next = node;
            previous = node;
        }
        deleted_contents = 0;
        if (created)
            ft_lstclear(&head, count_and_free);
        snprintf(label, sizeof(label), "clear %zu nodes, del called %zu times", length, length);
        check(label, created && head == NULL && deleted_contents == (int)length);
        if (!created)
        {
            while (head != NULL)
            {
                node = head->next;
                free(head->content);
                free(head);
                head = node;
            }
        }
    }
}

void test_ft_lstiter(void)
{
    t_list nodes[11];
    int values[11];
    size_t length;
    size_t j;
    int passed;
    char label[80];

    for (length = 0; length <= 10; length++)
    {
        for (j = 0; j < COUNT(nodes); j++)
        {
            values[j] = (int)j * 10;
            nodes[j].content = &values[j];
            nodes[j].next = j + 1 < length ? &nodes[j + 1] : NULL;
        }
        visited_nodes = 0;
        ft_lstiter(length ? &nodes[0] : NULL, increase_integer);
        passed = visited_nodes == (int)length;
        for (j = 0; j < COUNT(values); j++)
        {
            if (values[j] != (int)j * 10 + (j < length ? 1 : 0))
                passed = 0;
        }
        snprintf(label, sizeof(label), "visit %zu nodes exactly once", length);
        check(label, passed);
    }
}

void test_ft_lstmap(void)
{
    t_list original[10];
    int values[10];
    t_list *mapped;
    t_list *current;
    t_list *next;
    size_t length;
    size_t j;
    int passed;
    char label[80];

    for (length = 0; length <= COUNT(original); length++)
    {
        for (j = 0; j < COUNT(original); j++)
        {
            values[j] = (int)j * 17 + 1;
            original[j].content = &values[j];
            original[j].next = j + 1 < length ? &original[j + 1] : NULL;
        }
        mapped = ft_lstmap(length ? &original[0] : NULL,
            double_integer, count_and_free);
        passed = length == 0 ? mapped == NULL : mapped != NULL;
        current = mapped;
        for (j = 0; passed && j < length; j++)
        {
            if (current == NULL || current == &original[j] || current->content == NULL)
            {
                passed = 0;
                break;
            }
            if (current->content == original[j].content
                || *(int *)current->content != values[j] * 2)
                passed = 0;
            if (values[j] != (int)j * 17 + 1)
                passed = 0;
            current = current->next;
        }
        if (passed && current != NULL)
            passed = 0;
        snprintf(label, sizeof(label), "map %zu nodes, independent doubled contents", length);
        check(label, passed);
        current = mapped;
        j = 0;
        while (current != NULL && j < length + 1)
        {
            next = current->next;
            free(current->content);
            free(current);
            current = next;
            j++;
        }
    }
}

/* ==================== LAUNCH ALL 40 FUNCTIONS ==================== */

int main(void)
{
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));
    delay_between_tests = read_delay("DESTRUCTOR_DELAY_US", 7500);
    delay_between_functions = read_delay("DESTRUCTOR_FUNCTION_DELAY_US", 1200000);
    show_passes = !read_delay("DESTRUCTOR_QUIET", 0);
    stop_on_failure = read_delay("DESTRUCTOR_STOP_FIRST", 0) != 0;

    printf("%s============================================================%s\n", GOLD, RESET);
    printf("%s        LIBFT DECIMATOR 4K  |  FINAL EDITION%s\n", GOLD, RESET);
    printf("%s             40 functions / 30 cases maximum%s\n", GOLD, RESET);
    printf("%s============================================================%s\n", GOLD, RESET);

    run_test("ft_isalpha", test_ft_isalpha);
    run_test("ft_isdigit", test_ft_isdigit);
    run_test("ft_isalnum", test_ft_isalnum);
    run_test("ft_isascii", test_ft_isascii);
    run_test("ft_isprint", test_ft_isprint);
    run_test("ft_toupper", test_ft_toupper);
    run_test("ft_tolower", test_ft_tolower);
    run_test("ft_strlen", test_ft_strlen);
    run_test("ft_memset", test_ft_memset);
    run_test("ft_bzero", test_ft_bzero);
    run_test("ft_memcpy", test_ft_memcpy);
    run_test("ft_memmove", test_ft_memmove);
    run_test("ft_strchr", test_ft_strchr);
    run_test("ft_strrchr", test_ft_strrchr);
    run_test("ft_strncmp", test_ft_strncmp);
    run_test("ft_memchr", test_ft_memchr);
    run_test("ft_memcmp", test_ft_memcmp);
    run_test("ft_atoi", test_ft_atoi);
    run_test("ft_calloc", test_ft_calloc);
    run_test("ft_strdup", test_ft_strdup);
    run_test("ft_substr", test_ft_substr);
    run_test("ft_strjoin", test_ft_strjoin);
    run_test("ft_strtrim", test_ft_strtrim);
    run_test("ft_split", test_ft_split);
    run_test("ft_itoa", test_ft_itoa);
    run_test("ft_strmapi", test_ft_strmapi);
    run_test("ft_striteri", test_ft_striteri);
    run_test("ft_putchar_fd", test_ft_putchar_fd);
    run_test("ft_putstr_fd", test_ft_putstr_fd);
    run_test("ft_putendl_fd", test_ft_putendl_fd);
    run_test("ft_putnbr_fd", test_ft_putnbr_fd);
    run_test("ft_lstnew", test_ft_lstnew);
    run_test("ft_lstadd_front", test_ft_lstadd_front);
    run_test("ft_lstsize", test_ft_lstsize);
    run_test("ft_lstlast", test_ft_lstlast);
    run_test("ft_lstadd_back", test_ft_lstadd_back);
    run_test("ft_lstdelone", test_ft_lstdelone);
    run_test("ft_lstclear", test_ft_lstclear);
    run_test("ft_lstiter", test_ft_lstiter);
    run_test("ft_lstmap", test_ft_lstmap);

    printf("\n%s============================================================%s\n", GOLD, RESET);
    printf("%s  FINAL RESULT: %d PASSED / %d FAILED%s\n",
        total_failed ? ROSE : MINT, total_passed, total_failed, RESET);
    printf("%s============================================================%s\n", GOLD, RESET);
    if (total_failed == 0)
        printf("%s%s%s\n", MINT, success_messages[rand() % COUNT(success_messages)], RESET);
    else
        printf("%s%s%s\n", ROSE, failure_messages[rand() % COUNT(failure_messages)], RESET);
    return (total_failed != 0);
}
