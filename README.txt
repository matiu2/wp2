This is the witty plus version 2 library.

The witty-plus was not quite going the right way to be a library, and a lot of the auth stuff that it added was added in a better way in Wt itself.

It's a library that adds some less generic, but more immediately useful functionality to the witty library at http://webtoolkit.eu

It's licensed under the GPL2 so that you can link it with Wt.

Features:

 * Gives a base app with a lot of stuff used in dbo apps already there.
 * Provides simple virtual interfaces to speed up compile time, for example to get the dbSession:
     
    # include <wp2/db.hpp>
    Wt::Dbo::Session& db = wp2::db();
    
 * Ties together common controls, such as a label and a form widget, gives a choice of layout methods. For example:

    #include <wp2/FormHelper>
    auto helper = FormHelper(MyContainerWidget or MyLayoutManager);
    auto nameField = helper.addField<Wt::WComboBox>(tr("Name:"));
    auto btnBar = helper.btnBar();
    btnBar->OKHit().connect(this, &MyForm.saveChanges);

 * Provides easier internal URLManagement
   
    #include <wp2/iURLs>
    auto urls = wp2::iURLs::instance();
    urls->register("/page", [urls]() { showPage(urls->nextPart()) });
    urls->register("/page/edit", [urls]() { editPage(urls->nextPart()); });
    // Create an internal Path link
    urls->anchor(tr("Go to next Page"), "/page/4", myForm);

 * More stuff to go here as I think about it


Restrictions:

 * Needs a c++11 compatiblish compiler like gcc4.7
 * Make heavy use of virtual classes


Overview:

The source is organised in directories

 bin - this directory contains binaries for setting up new witty app directories
 wp2 - This is the library directory
 static - This contains static files that wp2 needs such as css and images.
 private - This contains private files that are not served on the web but needed by wp2, for example configuration files

 
How to use static:

When the library is compiled and installed, the static directory is installed in /usr/share/wp2/static. When your write your app, it's best if you either symlink it or copy it to a directory called wp2. Then when you launch your app, include it in the command line --docroot argument. For example --docroot=".;/wp2,/images,/style" where images and style are your 
 
 It's installed into /usr/share/wp2/static. When you include it in your app, 
