/*-
 * Copyright (c) 2011       Scott Ringwelski <sgringwe@mtu.edu>
 *
 * Originaly Written by Scott Ringwelski for BeatBox Music Player
 * BeatBox Music Player: http://www.launchpad.net/beat-box
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* Merely a place holder for multiple pieces of information regarding
 * the current song playing. Mostly here because of dependence. */

public class LastFM.Tag : Object {
	private string _tag;
	private string _url;
	
	public Tag.with_string(string tag) {
		_tag = tag;
	}
	
	public Tag.with_string_and_url(string tag, string url) {
		_tag = tag;
		_url = url;
	}
	
	public string tag {
		get { return _tag; } 
		set { _tag = value; }
	}
	
	public string url {
		get { return _url; }
		set { _url = value; }
	}
	
}
