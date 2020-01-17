/*
 * Copyright (c) 2018 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package org.elastos.carrier;

/**
 * A class representing the Carrier TURN Server information.
 *
 */

public class TurnServer {
    /**
     * TURN Server address max length.
     */
    public static final int MAX_TURN_SERVER_LEN = 63;

    /**
     * TURN Server user name max length.
     */
    public static final int MAX_TURN_USERNAME_LEN = 127;

    /**
     * TURN Server password max length.
     */
    public static final int MAX_TURN_PASSWORD_LEN = 63;

    /**
     * TURN Server realm max length.
     */
    public static final int MAX_TURN_REALM_LEN = 127;


    private String server;
    private int port;
    private String username;
    private String password;
    private String realm;

    protected TurnServer() {
    }


    /**
     * Get turn server address
     * @return
     */
    public String getServer() {
        return server;
    }

    /**
     * Set turn server address
     *
     * This function only be called in JNI.
     *
     * @param
     * 		server		The turn server address to set
     */
    public void setServer(String server) {
        if (server == null || server.length() > MAX_TURN_SERVER_LEN)
            throw new IllegalArgumentException("Invalid server length, expected (0, (0," +
                    MAX_TURN_SERVER_LEN + "]");

        this.server = server;
    }

    /**
     * Get turn server port
     * @return
     */
    public int getPort() {
        return port;
    }


    /**
     * Set turn server port
     *
     * This function only be called in JNI.
     *
     * @param
     * 		port		The turn server port to set
     */
    public void setPort(int port) {
        this.port = port;
    }

    /**
     * Get turn server username
     * @return
     */
    public String getUsername() {
        return username;
    }

    /**
     * Set turn server username
     *
     * This function only be called in JNI.
     *
     * @param
     * 		username		The turn server username to set
     */
    public void setUsername(String username) {
        if (username == null || username.length() > MAX_TURN_USERNAME_LEN)
            throw new IllegalArgumentException("Invalid username length, expected (0, (0," +
                    MAX_TURN_USERNAME_LEN + "]");

        this.username = username;
    }

    /**
     * Get turn server password
     * @return
     */
    public String getPassword() {
        return password;
    }

    /**
     * Set turn server password
     *
     * This function only be called in JNI.
     *
     * @param
     * 		password		The turn server password to set
     */
    public void setPassword(String password) {
        if (password == null || password.length() > MAX_TURN_PASSWORD_LEN)
            throw new IllegalArgumentException("Invalid password length, expected (0, (0," +
                    MAX_TURN_PASSWORD_LEN + "]");

        this.password = password;
    }

    /**
     * Get turn server realm
     * @return
     */
    public String getRealm() {
        return realm;
    }

    /**
     * Set turn server realm
     *
     * This function only be called in JNI.
     *
     * @param
     * 		realm		The turn server realm to set
     */
    public void setRealm(String realm) {
        if (realm == null || realm.length() > MAX_TURN_REALM_LEN)
            throw new IllegalArgumentException("Invalid realm length, expected (0, (0," +
                    MAX_TURN_REALM_LEN + "]");

        this.realm = realm;
    }

    /**
     * Get debug description of current UserInfo object.
     *
     * @return
     * 		The debug description of UserInfo object.
     */
    @Override
    public String toString() {
        return String.format("TurnServer[server:%s, port:%s, username:%s," +
                        "realm:%s", server, port, username, realm);
    }

}
