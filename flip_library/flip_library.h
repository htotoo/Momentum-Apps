#ifndef FLIP_LIBRARY_E_H
#define FLIP_LIBRARY_E_H

#include <flipper_http/flipper_http.h>
#include <easy_flipper/easy_flipper.h>
#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/modules/submenu.h>
#include <gui/view_dispatcher.h>
#include <notification/notification.h>
#include <dialogs/dialogs.h>
#include <jsmn/jsmn.h>

#define TAG "FlipLibrary"

// Define the submenu items for our FlipLibrary application
typedef enum {
    FlipLibrarySubmenuIndexRandomFacts, // Click to run the random facts
    FlipLibrarySubmenuIndexDictionary, // click to view the dictionary variable item list
    FlipLibrarySubmenuIndexAbout, // Click to view the about screen
    FlipLibrarySubmenuIndexSettings, // Click to view the WiFi settings
    //
    FlipLibrarySubmenuIndexRandomFactsCats, // Click to view the random facts (cats)
    FlipLibrarySubmenuIndexRandomFactsDogs, // Click to view the random facts (dogs)
    FlipLibrarySubmenuIndexRandomFactsQuotes, // Click to view the random facts (quotes)
    FlipLibrarySubmenuIndexRandomFactsAll, // Click to view the random facts (all)
} FlipLibrarySubmenuIndex;

// Define a single view for our FlipLibrary application
typedef enum {
    FlipLibraryViewRandomFacts = 7, // The random facts main screen
    FlipLibraryViewLoader, // The loader screen retrieves data from the internet
    FlipLibraryViewSubmenuMain, // The submenu screen
    FlipLibraryViewAbout, // The about screen
    FlipLibraryViewSettings, // The settings screen
    FlipLibraryViewTextInputSSID, // The text input screen (SSID)
    FlipLibraryViewTextInputPassword, // The text input screen (password)
    FlipLibraryViewTextInputQuery, // Query the user for information
    FlipLibraryViewWidgetResult, // The text box that displays the random fact
} FlipLibraryView;

// Each screen will have its own view
typedef struct {
    ViewDispatcher* view_dispatcher; // Switches between our views
    View* view_loader; // The screen that loads data from internet
    Submenu* submenu_main; // The submenu for the main screen
    Submenu* submenu_random_facts; // The submenu for the random facts screen
    Widget* widget_about; // The widget for the about screen
    VariableItemList* variable_item_list_wifi; // The variable item list (WiFi settings)
    VariableItem* variable_item_ssid; // The variable item (SSID)
    VariableItem* variable_item_password; // The variable item (password)
    TextInput* uart_text_input_ssid; // The text input for the SSID
    TextInput* uart_text_input_password; // The text input for the password
    TextInput* uart_text_input_query; // The text input for querying information
    //
    Widget* widget_result; // The text box that displays the result

    char* uart_text_input_buffer_ssid; // Buffer for the text input (SSID)
    char* uart_text_input_temp_buffer_ssid; // Temporary buffer for the text input (SSID)
    uint32_t uart_text_input_buffer_size_ssid; // Size of the text input buffer (SSID)

    char* uart_text_input_buffer_password; // Buffer for the text input (password)
    char* uart_text_input_temp_buffer_password; // Temporary buffer for the text input (password)
    uint32_t uart_text_input_buffer_size_password; // Size of the text input buffer (password)

    char* uart_text_input_buffer_query; // Buffer for the text input (query)
    char* uart_text_input_temp_buffer_query; // Temporary buffer for the text input (query)
    uint32_t uart_text_input_buffer_size_query; // Size of the text input buffer (query)
} FlipLibraryApp;

// Function to free the resources used by FlipLibraryApp
void flip_library_app_free(FlipLibraryApp* app);
extern FlipLibraryApp* app_instance;
#endif // FLIP_LIBRARY_E_H
