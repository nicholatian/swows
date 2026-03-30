#!/usr/bin/env -S vala --pkg gtk4
/**********************************************************************\
 *                           POKeMON SwowS!                           *
 *                                                                    *
 *                Copyright (C) 2021 Alexander Nicholi                *
 *                    Released under BSD-0-Clause.                    *
\**********************************************************************/

public class Sablmap : Gtk.Application
{
private Gtk.DrawingArea area;
private Gtk.ApplicationWindow window;

public Sablmap( )
{
	Object(
		application_id: "com.nicholatian.sablmap" );
}

private void redraw( Gtk.DrawingArea area, Cairo.Context cairo,
	int width, int height )
{
	Gdk.RGBA col = Gdk.RGBA( );

	col.blue = 1.0f;
	col.green = 0.5f;

	cairo.arc( width / 2.0,
		height / 2.0,
		int.min(width, height) / 2.0,
		0,
		2 * 3.14159 );

	cairo.fill( );
}

public override void activate( )
{
	this.window = new Gtk.ApplicationWindow( this )
	{
		title = "SablMap", default_width = 960, default_height = 540
	};

	this.area = new Gtk.DrawingArea( )
	{
		content_width = 960, content_height = 540
	};

	this.area.set_draw_func( this.redraw );
}
}

/* *** */

public class TextFileViewerSample : Gtk.Application
{
private Gtk.TextView text_view;
private Gtk.ApplicationWindow window;

public TextFileViewerSample( )
{
	Object( application_id:
	        "com.example.TextFileViewerSample" );
}

public override void
activate( )
{
	this.window = new Gtk.ApplicationWindow( this )
	{
		title = "Text File Viewer", default_width = 400,
		default_height = 300
	};

	var toolbar = new Gtk.Box( Gtk.Orientation.HORIZONTAL, 0 );
	toolbar.add_css_class( "toolbar" );

	var open_image = new Gtk.Image.from_icon_name( "document-open" )
	;
	var open_label = new Gtk.Label( "Open" );

	var open_button_box = new Gtk.Box( Gtk.Orientation.HORIZONTAL,
	                                   0 );
	open_button_box.append( open_image );
	open_button_box.append( open_label );

	var open_button = new Gtk.Button( );
	open_button.child = open_button_box;
	open_button.clicked.connect( on_open_button_clicked );

	toolbar.append( open_button );

	this.text_view = new Gtk.TextView( )
	{
		editable = false, cursor_visible = false,
	};

	var scroll_view = new Gtk.ScrolledWindow( )
	{
		hscrollbar_policy = Gtk.PolicyType.AUTOMATIC,
		vscrollbar_policy = Gtk.PolicyType.AUTOMATIC, vexpand
		        = true, valign = Gtk.Align.FILL, child = this.
		                                                 text_view,
	};

	var vbox = new Gtk.Box( Gtk.Orientation.VERTICAL, 0 );
	vbox.append( toolbar );
	vbox.append( scroll_view );

	this.window.child = vbox;
	this.window.present( );
}

private void
on_open_button_clicked( )
{
	var file_dialog = new Gtk.FileDialog( )
	{
		title = "Open File"
	};

	file_dialog.open.begin( this.window,
	                        null,
	                        ( obj, res ) => {
			try
			{
				var file = file_dialog.open.end( res );
				uint8[] contents;
				file.load_contents( null, out contents,
				                    null );
				this.text_view.buffer.text = (string)
				                             contents;
			}
			catch (Error e)
			{
				stderr.printf( "Error: %s\n",
				               e.message );
			}
		} );
}

public static int
main( string[] args )
{
	var app = new TextFileViewerSample( );

	return app.run( args );
}

} /* class TextFileViewerSample */
