### README ###


INTRODUCTION
---------------------

We have created two modules, listed as: 

i. Metadata_Catalog and 
ii. XML2MetaData

These modules help us import data from xml (in FGDC, Federal Geographic Data Committee standard) into the drupal nodes. Metadata_Catalog module is acutally a feature module which creates the content type required for XML to hold the data and XML2MetaData ultimately creates an interface and backend codes to facilitate importing of the XML into Drupal nodes.Metadata Catalog also helps user create their own FGDC standard metadata.
To know more about the FGDC standard, follow through:
http://www.fgdc.gov/metadata/csdgm 


REQUIREMENTS
---------------------

To add the Metadata Catalog Module, we need to make sure that following modules are installed /enabled:
• Cck_select_other,
• Ctools ,i.e. Chaos tools,
• Features, 
• Entity API,
• Field_collection, 
• Field_group,
• Link

To add the XML2MetaData Module, we need to make sure that following module is installed /enabled:
• Metadata_catalog

So, every prerequisite that holds for Metadata Catalog Module also holds for XML2MetaData.


INSTALLATION
---------------------

Firstly we need to make sure that the settings in PHP is configured properly by allocating more time (generally it is 30 seconds, we may change it to 400 seconds) and memory (it is 128 Mb, we may want change it to 1024Mb).

i. Install both the modules "metadata_catalog" and "xml2metadata" by copying them to [drupal]\sites\all\modules\
ii. First enable "metadata_catalog" and then "xml2metadata" respectively
iii. You also have to apply a patch for the field_collection module to work properly [upto version 7.x-1.0-beta4]. The patch named field_collection.patch” is provided along with the module. 
OR 
You can change the piece of code by yourself, you have to go to field_collection.module file (field_collection module) and edit the line 978 which reads as follows:

if ($recursion++ > 3) {

--Update the value from 3 to 4, which means we need 4 recursive loops of field_collection.


TESTING
---------------------

For Metadata Catalog Module, once you install it, you will find a content type called "Metadata" in ADD CONTENT option
If you haven't done the patch, you may see the error message. Otherwise you can start creating contents as per the FGDC standard.

For XML2MetaData module, the default location is:
<BaseURL>/xml2metadata and it also appears in Navigation Menu.
The interface is quite simple and once you successfully create a node from XML, you will see the success message.

