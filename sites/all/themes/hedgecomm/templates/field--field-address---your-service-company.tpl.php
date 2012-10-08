<?php
/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>
<!--
THIS FILE IS NOT USED AND IS HERE AS A STARTING POINT FOR CUSTOMIZATION ONLY.
See http://api.drupal.org/api/function/theme_field/7 for details.
After copying this file to your theme's folder and customizing it, remove this
HTML comment.
-->
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php
$latitude = $items[0]['#location']['latitude'];
$longitude = $items[0]['#location']['longitude'];
$title = $element['#object']->title;
$view_mode = $element['#view_mode'];
?>

<script type="text/javascript">
function initialize() {
	var centerLatLng = new google.maps.LatLng(<?php print $latitude; ?>, <?php print $longitude; ?>);
  var mapOptions = {
    zoom: 15,
    disableDefaultUI: true,
    zoomControl: true,
    center: centerLatLng,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  }
  var map = new google.maps.Map(document.getElementById("map_canvas"), mapOptions);
  var marker = new google.maps.Marker({
    position: centerLatLng,
    map: map,
    title: "<?php print $title; ?>"
  });
}

function loadScript() {
  var script = document.createElement("script");
  script.type = "text/javascript";
  script.src = "http://maps.googleapis.com/maps/api/js?key=AIzaSyBexDEMMY6T6girz1qx2IP3-Lc2FtTKwwg&sensor=true&callback=initialize";
  document.body.appendChild(script);
}

window.onload = loadScript;
</script>

<div id="map_canvas" style="width: 250px; height: 150px;"></div>
<?php print render($items); ?>
</div>
